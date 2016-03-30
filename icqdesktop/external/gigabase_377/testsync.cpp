//-< TESTSYNC.CPP >--------------------------------------------------*--------*
// GigaBASE                  Version 1.0         (c) 1999  GARRET    *     ?  *
// (Post Relational Database Management System)                      *   /\|  *
//                                                                   *  /  \  *
//                          Created:     20-Dec-98    K.A. Knizhnik  * / [] \ *
//                          Last update: 12-Jan-98    K.A. Knizhnik  * GARRET *
//-------------------------------------------------------------------*--------*
// Test for interprocess and interthread synchronization
//-------------------------------------------------------------------*--------*

#include "gigabase.h"
#include <stdio.h>

USE_GIGABASE_NAMESPACE

const int nRecords = 100000;
const int nSequentialSearches = 1;

class Record {
  public:
    char const* key;

    TYPE_DESCRIPTOR((KEY(key, HASHED|INDEXED)));
};

REGISTER(Record);

dbDatabase db;

time_t commitDelay;

void thread_proc doTest(void* arg)
{
    int  i, n;
    int  id = (int)(size_t)arg;
    char buf[32];

    db.attach();

    nat8 key = 1999;
    time_t start = time(NULL);
    for (i = 0; i < nRecords; i++) {
        Record rec;
        key = (3141592621u*key + 2718281829u) % 1000000007u;
        sprintf(buf, INT8_FORMAT ".%d", key, id);
        rec.key = buf;
        insert(rec);
        if (commitDelay != 0) { 
            db.commit();
        } else { 
            db.precommit();
        }
    }
    db.commit();
    printf("Elapsed time for inserting %d record: %d seconds\n",
           nRecords, int(time(NULL) - start));
    start = time(NULL);
    dbQuery q;
    dbCursor<Record> cursor;
    dbCursor<Record> updateCursor(dbCursorForUpdate);
    q = "key=",buf;
    start = time(NULL);
    key = 1999;
    for (i = 0; i < nRecords; i++) {
        key = (3141592621u*key + 2718281829u) % 1000000007u;
        sprintf(buf, INT8_FORMAT ".%d", key, id);
        n = cursor.select(q);
        assert(n == 1);
        db.commit();
    }
    printf("Elapsed time for %d index searches: %d seconds\n",
           nRecords, int(time(NULL) - start));
    q = "key like",buf;
    sprintf(buf, "%%.%d", id);
    cursor.unsetSelectionLimit();
    start = time(NULL);
    for (i = 0; i < nSequentialSearches; i++) {
        n = cursor.select(q);
        assert(n == nRecords);
        db.commit();
    }
    printf("Elapsed time for %d sequential search through %d records: "
           "%d seconds\n", nSequentialSearches, nRecords,
           int(time(NULL) - start));

    q = "key like",buf,"order by key";
    start = time(NULL);
    for (i = 0; i < nSequentialSearches; i++) {
        n = cursor.select(q);
        assert(n == nRecords);
        char const* curr = cursor->key;
        for (n = nRecords; --n != 0;) {
            if (n % 100) { 
                cursor.freeze();
                db.commit();
                cursor.unfreeze();
            }
            char const* succ = cursor.next()->key;
            assert(strcmp(succ, curr) > 0);
            curr = succ;
        }
        db.commit();
    }
    printf("Elapsed time for %d searchs with sorting %d records: %d seconds\n",
           nSequentialSearches, nRecords, int(time(NULL)-start));
    start = time(NULL);
    q = "key like",buf;
    sprintf(buf, "1%%.%d", id);
    n = updateCursor.select(q);
    for (i = 0; i < n; i++) {
        updateCursor.remove();
    }
    assert(updateCursor.get() == NULL);
    db.commit();
    sprintf(buf, "%%.%d", id);
    n += updateCursor.select(q);
    assert(n == nRecords);
    updateCursor.removeAllSelected();
    db.commit();
    printf("Elapsed time for deleting all %d records: %d seconds\n",
           nRecords, int(time(NULL) - start));
    db.detach();
}

int __cdecl main(int argc, char* argv[])
{
    int i, id = 0;
    int nThreads = 1;

    if (argc > 1) {
        nThreads = atoi(argv[1]);
    }
    if (argc > 2) {
        id = atoi(argv[2]);
    }
    dbThread* thread = new dbThread[nThreads];

    char* env = getenv("GIGABASE_COMMIT_DELAY");
    if (env != NULL) { 
        commitDelay = atoi(env);
    }
    if (db.open("testsync.dbs", commitDelay)) {
        db.setConcurrency(0);
        for (i = 0; i < nThreads; i++) {
            thread[i].create(doTest, (void*)id++);
        }
        for (i = 0; i < nThreads; i++) {
            thread[i].join();
        }
        db.close();
        return EXIT_SUCCESS;
    } else {
        printf("Failed to open database\n");
        return EXIT_FAILURE;
    }
}











