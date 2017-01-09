#pragma once
#include <windows.h>

#include <dshow.h>

class CVideoRenderer;

enum PlaybackState
{
	STATE_NO_GRAPH,
	STATE_RUNNING,
	STATE_PAUSED,
	STATE_STOPPED,
};

const UINT WM_GRAPH_EVENT = WM_APP + 1;

typedef void (CALLBACK *GraphEventFN)(HWND hwnd, long eventCode, LONG_PTR param1, LONG_PTR param2);

class DShowPlayer
{
public:
	DShowPlayer(HWND hwnd);
	~DShowPlayer();

	PlaybackState State() const { return m_state; }

	BOOL OpenFile(PCWSTR pszFileName);

	BOOL Play();
	BOOL Pause();
	BOOL Stop();

	BOOL    HasVideo() const;
	BOOL UpdateVideoWindow(const LPRECT prc);
	BOOL Repaint(HDC hdc);
	BOOL DisplayModeChanged();

	BOOL HandleGraphEvent(GraphEventFN pfnOnGraphEvent);

private:
	BOOL InitializeGraph();
	void    TearDownGraph();
	BOOL CreateVideoRenderer();
	BOOL RenderStreams(IBaseFilter *pSource);

	PlaybackState   m_state;

	HWND m_hwnd; // Video window. This window also receives graph events.

	IGraphBuilder   *m_pGraph;
	IMediaControl   *m_pControl;
	IMediaEventEx   *m_pEvent;
	CVideoRenderer  *m_pVideo;
};

