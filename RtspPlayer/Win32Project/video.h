
#pragma once
#include <windows.h>
#include <dshow.h>
#include <d3d9.h>
#include <Vmr9.h>
#include <Evr.h>

template <class T> void SafeRelease(T **ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}

BOOL RemoveUnconnectedRenderer(IGraphBuilder *pGraph, IBaseFilter *pRenderer, BOOL *pbRemoved);
BOOL AddFilterByCLSID(IGraphBuilder *pGraph, REFGUID clsid, IBaseFilter **ppF, LPCWSTR wszName);

// Abstract class to manage the video renderer filter.
// Specific implementations handle the VMR-7, VMR-9, or EVR filter.

class CVideoRenderer
{
public:
	virtual ~CVideoRenderer() {};
	virtual BOOL    HasVideo() const = 0;
	virtual BOOL AddToGraph(IGraphBuilder *pGraph, HWND hwnd) = 0;
	virtual BOOL FinalizeGraph(IGraphBuilder *pGraph) = 0;
	virtual BOOL UpdateVideoWindow(HWND hwnd, const LPRECT prc) = 0;
	virtual BOOL Repaint(HWND hwnd, HDC hdc) = 0;
	virtual BOOL DisplayModeChanged() = 0;
};

// Manages the VMR-7 video renderer filter.

class CVMR7 : public CVideoRenderer
{
	IVMRWindowlessControl   *m_pWindowless;

public:
	CVMR7();
	~CVMR7();
	BOOL    HasVideo() const;
	BOOL AddToGraph(IGraphBuilder *pGraph, HWND hwnd);
	BOOL FinalizeGraph(IGraphBuilder *pGraph);
	BOOL UpdateVideoWindow(HWND hwnd, const LPRECT prc);
	BOOL Repaint(HWND hwnd, HDC hdc);
	BOOL DisplayModeChanged();
};


// Manages the VMR-9 video renderer filter.

class CVMR9 : public CVideoRenderer
{
	IVMRWindowlessControl9 *m_pWindowless;

public:
	CVMR9();
	~CVMR9();
	BOOL    HasVideo() const;
	BOOL AddToGraph(IGraphBuilder *pGraph, HWND hwnd);
	BOOL FinalizeGraph(IGraphBuilder *pGraph);
	BOOL UpdateVideoWindow(HWND hwnd, const LPRECT prc);
	BOOL Repaint(HWND hwnd, HDC hdc);
	BOOL DisplayModeChanged();
};


// Manages the EVR video renderer filter.

class CEVR : public CVideoRenderer
{
	IBaseFilter            *m_pEVR;
	IMFVideoDisplayControl *m_pVideoDisplay;

public:
	CEVR();
	~CEVR();
	BOOL    HasVideo() const;
	BOOL AddToGraph(IGraphBuilder *pGraph, HWND hwnd);
	BOOL FinalizeGraph(IGraphBuilder *pGraph);
	BOOL UpdateVideoWindow(HWND hwnd, const LPRECT prc);
	BOOL Repaint(HWND hwnd, HDC hdc);
	BOOL DisplayModeChanged();
};

