#pragma once

#include "utils/translator.h"
#include "../gui.shared/constants.h"
#include "../common.shared/constants.h"
#include "../common.shared/common_defs.h"

#if defined (_WIN32)

#define WINVER 0x0500
#define _WIN32_WINDOWS 0x0500
#define _WIN32_WINNT 0x0600

#include <array>
#include <cassert>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <type_traits>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <deque>
#include <sstream>
#include <iomanip>
#include <atomic>
#include <codecvt>
#include <assert.h>
#include <xutility>
#include <limits>
#include <cmath>
#include <mutex>

#include <stdint.h>

#ifdef _WIN32
#include <tchar.h>
#include <strsafe.h>
#include <sdkddkver.h>
#include <strsafe.h>
#include <Windows.h>
#include <sal.h>
#include <Psapi.h>
#include <ObjBase.h>
#include <ShObjIdl.h>
#include <propvarutil.h>
#include <functiondiscoverykeys.h>
#include <intsafe.h>
#include <guiddef.h>
#include <atlbase.h>
#include <atlstr.h>
#include <atlwin.h>
#endif //_WIN32

#include <QResource>
#include <QTranslator>
#include <QScreen>
#include <QtPlugin>
#include <QLibrary>
#include <QGuiApplication>
#include <QShowEvent>
#include <QComboBox>
#include <QMainWindow>
#include <QPushButton>
#include <QStyleOptionViewItem>
#include <QListWidget>
#include <QPaintEvent>
#include <QBitmap>
#include <QLinearGradient>
#include <QGraphicsOpacityEffect>
#include <QGraphicsBlurEffect>
#include <QCommonStyle>
#include <QListView>
#include <QLabel>
#include <QSizePolicy>
#include <QFont>
#include <QFile>
#include <QXmlStreamReader>
#include <QBuffer>
#include <QImage>
#include <QList>
#include <QString>
#include <QObject>
#include <QTime>
#include <QStringList>
#include <QTimer>
#include <QItemDelegate>
#include <QAbstractListModel>
#include <QHash>
#include <QApplication>
#include <QSize>
#include <QDate>
#include <QMutex>
#include <QScrollBar>
#include <QtConcurrent/QtConcurrent>
#include <QMap>
#include <QTextStream>
#include <QWidget>
#include <QTreeView>
#include <QBoxLayout>
#include <QHeaderView>
#include <QCompleter>
#include <QStandardItemModel>
#include <QPainter>
#include <QLineEdit>
#include <QKeyEvent>
#include <QTextEdit>
#include <QMetaType>
#include <QVariant>
#include <QDateTime>
#include <qframe.h>
#include <QDesktopWidget>
#include <QTextFrame>
#include <QScrollArea>
#include <QStackedWidget>
#include <QTableView>
#include <QMapIterator>
#include <QScroller>
#include <QAbstractTextDocumentLayout>
#include <QFileDialog>
#include <QTextDocumentFragment>
#include <QPixmapCache>
#include <QTextBrowser>
#include <QClipboard>

#include <QGraphicsDropShadowEffect>
#include <QProxyStyle>
#include <QDesktopServices>
#include <QCheckBox>

#include <QDesktopWidget>
#include <QSystemTrayIcon>
#include <QMenu>

#include <QMovie>
#include <QGestureEvent>
 
#undef min
#undef max
#undef small

#elif defined (__linux__)

#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <type_traits>
#include <map>
#include <set>
#include <array>
#include <vector>
#include <stack>
#include <sstream>
#include <iomanip>
#include <atomic>
#include <codecvt>
#include <assert.h>
#include <limits>
#include <stdint.h>

#include <QtCore/qresource.h>
#include <QtCore/qtranslator.h>
#include <QtGui/qscreen.h>
#include <QtCore/qplugin.h>
#include <QtCore/qlibrary.h>
#include <QtGui/qguiapplication.h>
#include <QtGui/qevent.h>
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qstyleoption.h>
#include <QtWidgets/qlistwidget.h>
#include <QtGui/qbitmap.h>
#include <QtGui/qbrush.h>
#include <QtWidgets/qgraphicseffect.h>
#include <QtWidgets/qcommonstyle.h>
#include <QtWidgets/qlistview.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qsizepolicy.h>
#include <QtGui/qfont.h>
#include <QtCore/qfile.h>
#include <QtCore/qxmlstream.h>
#include <QtCore/qbuffer.h>
#include <QtGui/qimage.h>
#include <QtCore/qlist.h>
#include <QtCore/qglobal.h>
#include <QtCore/qstring.h>
#include <QtCore/qobject.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qtimer.h>
#include <QtWidgets/qitemdelegate.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qhash.h>
#include <QtWidgets/qapplication.h>
#include <QtCore/qsize.h>
#include <QtCore/qmutex.h>
#include <QtWidgets/qscrollbar.h>

#include <QtConcurrent/qtconcurrentcompilertest.h>
#include <QtConcurrent/qtconcurrentexception.h>
#include <QtConcurrent/qtconcurrentfilter.h>
#include <QtConcurrent/qtconcurrentfilterkernel.h>
#include <QtConcurrent/qtconcurrentfunctionwrappers.h>
#include <QtConcurrent/qtconcurrentiteratekernel.h>
#include <QtConcurrent/qtconcurrentmap.h>
#include <QtConcurrent/qtconcurrentmapkernel.h>
#include <QtConcurrent/qtconcurrentmedian.h>
#include <QtConcurrent/qtconcurrentreducekernel.h>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QtConcurrent/qtconcurrentrunbase.h>
#include <QtConcurrent/qtconcurrentstoredfunctioncall.h>
#include <QtConcurrent/qtconcurrentthreadengine.h>
#include <QtConcurrent/qtconcurrentversion.h>

#include <QtCore/qmap.h>
#include <QtCore/qtextstream.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qtreeview.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qheaderview.h>
#include <QtWidgets/qcompleter.h>
#include <QtGui/qstandarditemmodel.h>
#include <QtGui/qpainter.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qtextedit.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qvariant.h>
#include <QtWidgets/qframe.h>
#include <QtWidgets/qdesktopwidget.h>
#include <QtWidgets/qscrollarea.h>
#include <QtWidgets/qstackedwidget.h>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qscroller.h>
#include <QtGui/qabstracttextdocumentlayout.h>
#include <QtWidgets/qfiledialog.h>
#include <QtGui/qtextdocumentfragment.h>
#include <QtGui/qpixmapcache.h>
#include <QtWidgets/qtextbrowser.h>
#include <QtWidgets/qdesktopwidget.h>
#include <QtCore/qeasingcurve.h>
#include <QtCore/qpropertyanimation.h>
#include <QtGui/qtextobject.h>
#include <QtCore/qmimedata.h>
#include <QtWidgets/qcheckbox.h>
#include <QtCore/qabstractnativeeventfilter.h>
#include <QtGui/qdesktopservices.h>
#include <QtGui/qtextcursor.h>
#include <QtCore/qprocess.h>
#include <QtWidgets/qproxystyle.h>
#include <QtWidgets/qdesktopwidget.h>
#include <QtWidgets/qsystemtrayicon.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qmenubar.h>
#include <QtGui/qclipboard.h>
#include <QtGui/qmovie.h>
#include <QtWidgets/qgesture.h>
#include <QtCore/quuid.h>
/*
#include <QtNetwork/qnetworkrequest.h>
#include <QtNetwork/qnetworkreply.h>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qhttpmultipart.h>
#include <QtCore/qurlquery.h>
*/
 
#define assert(e) { }

#include "../corelib/common.h"

#else

#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <type_traits>
#include <map>
#include <set>
#include <array>
#include <vector>
#include <stack>
#include <deque>
#include <sstream>
#include <iomanip>
#include <atomic>
#include <codecvt>
#include <assert.h>
#include <limits>

#include <stdint.h>

#import <QtCore/qresource.h>
#import <QtCore/qtranslator.h>
#import <QtGui/qscreen.h>
#import <QtCore/qplugin.h>
#import <QtCore/qlibrary.h>
#import <QtGui/qguiapplication.h>
#import <QtGui/qevent.h>
#import <QtWidgets/qcombobox.h>
#import <QtWidgets/qmainwindow.h>
#import <QtWidgets/qpushbutton.h>
#import <QtWidgets/qstyleoption.h>
#import <QtWidgets/qlistwidget.h>
#import <QtGui/qbitmap.h>
#import <QtGui/qbrush.h>
#import <QtWidgets/qgraphicseffect.h>
#import <QtWidgets/qcommonstyle.h>
#import <QtWidgets/qlistview.h>
#import <QtWidgets/qlabel.h>
#import <QtWidgets/qsizepolicy.h>
#import <QtGui/qfont.h>
#import <QtCore/qfile.h>
#import <QtCore/qxmlstream.h>
#import <QtCore/qbuffer.h>
#import <QtGui/qimage.h>
#import <QtCore/qlist.h>
#import <QtCore/qglobal.h>
#import <QtCore/qstring.h>
#import <QtCore/qobject.h>
#import <QtCore/qdatetime.h>
#import <QtCore/qstringlist.h>
#import <QtCore/qtimer.h>
#import <QtWidgets/qitemdelegate.h>
#import <QtCore/qabstractitemmodel.h>
#import <QtCore/qhash.h>
#import <QtWidgets/qapplication.h>
#import <QtCore/qsize.h>
#import <QtCore/qmutex.h>
#import <QtWidgets/qscrollbar.h>

#import <QtConcurrent/qtconcurrentcompilertest.h>
#import <QtConcurrent/qtconcurrentexception.h>
#import <QtConcurrent/qtconcurrentfilter.h>
#import <QtConcurrent/qtconcurrentfilterkernel.h>
#import <QtConcurrent/qtconcurrentfunctionwrappers.h>
#import <QtConcurrent/qtconcurrentiteratekernel.h>
#import <QtConcurrent/qtconcurrentmap.h>
#import <QtConcurrent/qtconcurrentmapkernel.h>
#import <QtConcurrent/qtconcurrentmedian.h>
#import <QtConcurrent/qtconcurrentreducekernel.h>
#import <QtConcurrent/qtconcurrentrun.h>
#import <QtConcurrent/qtconcurrentrunbase.h>
#import <QtConcurrent/qtconcurrentstoredfunctioncall.h>
#import <QtConcurrent/qtconcurrentthreadengine.h>
#import <QtConcurrent/qtconcurrentversion.h>

#import <QtCore/qmap.h>
#import <QtCore/qtextstream.h>
#import <QtWidgets/qwidget.h>
#import <QtWidgets/qtreeview.h>
#import <QtWidgets/qboxlayout.h>
#import <QtWidgets/qheaderview.h>
#import <QtWidgets/qcompleter.h>
#import <QtGui/qstandarditemmodel.h>
#import <QtGui/qpainter.h>
#import <QtWidgets/qlineedit.h>
#import <QtWidgets/qtextedit.h>
#import <QtCore/qmetatype.h>
#import <QtCore/qvariant.h>
#import <QtWidgets/qframe.h>
#import <QtWidgets/qdesktopwidget.h>
#import <QtWidgets/qscrollarea.h>
#import <QtWidgets/qstackedwidget.h>
#import <QtWidgets/qtableview.h>
#import <QtWidgets/qscroller.h>
#import <QtGui/qabstracttextdocumentlayout.h>
#import <QtWidgets/qfiledialog.h>
#import <QtGui/qtextdocumentfragment.h>
#import <QtGui/qpixmapcache.h>
#import <QtWidgets/qtextbrowser.h>
#import <QtWidgets/qdesktopwidget.h>
#import <QtCore/qeasingcurve.h>
#import <QtCore/qpropertyanimation.h>
#import <QtGui/qtextobject.h>
#import <QtCore/qmimedata.h>
#import <QtWidgets/qcheckbox.h>
#import <QtCore/qabstractnativeeventfilter.h>
#import <QtGui/qdesktopservices.h>
#import <QtGui/qtextcursor.h>
#import <QtCore/qprocess.h>
#import <QtWidgets/qproxystyle.h>
#import <QtWidgets/qdesktopwidget.h>
#import <QtWidgets/qsystemtrayicon.h>
#import <QtWidgets/qmenu.h>
#import <QtWidgets/qmenubar.h>
#import <QtGui/qclipboard.h>
#import <QtCore/QObjectCleanupHandler.h>
#import <QtGui/qmovie.h>
#import <QtWidgets/qgesture.h>
#import <QtCore/QUuid.h>
/*
#import <QtNetwork/qnetworkrequest.h>
#import <QtNetwork/qnetworkreply.h>
#import <QtNetwork/qnetworkaccessmanager.h>
#import <QtNetwork/qhttpmultipart.h>
#import <QtCore/qurlquery.h>
*/

#define assert(e) { if (!(e)) puts("ASSERT: " #e); }

#include "macconfig.h"

//#include <QGraphicsDropShadowEffect>
//#include <QProxyStyle>
#endif // _WIN32

#include "../corelib/common.h"
#ifndef _WIN32
    #define MAC_OS
#endif
