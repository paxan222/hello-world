#ifndef _SNAPSHOT_DOWN_PARAM_H_
#define _SNAPSHOT_DOWN_PARAM_H_

#include "SNPlatOS.h"
#include "AlarmExType.h"
class SN_DLL_API SnapshotDownParam
{
public:
	explicit SnapshotDownParam();
	SnapshotDownParam(const SnapshotDownParam& Snap);
	~SnapshotDownParam();
	void setCameraID(int p_nCameraID);
	const int getCameraID() const;

	void setSnapTime(const INT64& p_nSnapTime);
	const INT64   getSnapTime() const;

	void setSnapAlarmType(const AlarmExType& p_nSnapAlarmType);
	const AlarmExType&  getSnapAlarmType() const;

	void setSnapIndex(int p_nSnapIndex);
	const int   getSnapIndex() const;

	SnapshotDownParam& operator = (const SnapshotDownParam& Snap);
private:
	int                      m_nCameraID;
	INT64                 m_nSnapTime;
	AlarmExType      m_nSnapAlarmType;
	int                      m_nSnapIndex;
};

#endif	//_REMOTE_SNAPSHOT_PARAM_H_

