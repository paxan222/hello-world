#include "stdafx.h"
#include "video.h"
#include <Mfidl.h>
#include <uuids.h>
#include <evr.h>

BOOL InitializeEVR(IBaseFilter *pEVR, HWND hwnd, IMFVideoDisplayControl ** ppWc);
BOOL InitWindowlessVMR9(IBaseFilter *pVMR, HWND hwnd, IVMRWindowlessControl9 ** ppWc);
BOOL InitWindowlessVMR(IBaseFilter *pVMR, HWND hwnd, IVMRWindowlessControl** ppWc);
BOOL FindConnectedPin(IBaseFilter *pFilter, PIN_DIRECTION PinDir, IPin **ppPin);

/// VMR-7 Wrapper

CVMR7::CVMR7() : m_pWindowless(NULL)
{

}

CVMR7::~CVMR7()
{
	SafeRelease(&m_pWindowless);
}

BOOL CVMR7::HasVideo() const
{
	return (m_pWindowless != NULL);
}

BOOL CVMR7::AddToGraph(IGraphBuilder *pGraph, HWND hwnd)
{
	IBaseFilter *pVMR = NULL;

	BOOL hr = AddFilterByCLSID(pGraph, CLSID_VideoMixingRenderer,&pVMR, L"VMR-7");

	if (SUCCEEDED(hr))
	{
		// Set windowless mode on the VMR. This must be done before the VMR
		// is connected.
		hr = InitWindowlessVMR(pVMR, hwnd, &m_pWindowless);
	}
	SafeRelease(&pVMR);
	return hr;
}

BOOL CVMR7::FinalizeGraph(IGraphBuilder *pGraph)
{
	if (m_pWindowless == NULL)
	{
		return TRUE;
	}

	IBaseFilter *pFilter = NULL;

	BOOL hr = m_pWindowless->QueryInterface(IID_PPV_ARGS(&pFilter));
	if (FAILED(hr))
	{
		goto done;
	}

	BOOL bRemoved;
	hr = RemoveUnconnectedRenderer(pGraph, pFilter, &bRemoved);

	// If we removed the VMR, then we also need to release our 
	// pointer to the VMR's windowless control interface.
	if (bRemoved)
	{
		SafeRelease(&m_pWindowless);
	}

done:
	SafeRelease(&pFilter);
	return hr;
}

BOOL CVMR7::UpdateVideoWindow(HWND hwnd, const LPRECT prc)
{
	if (m_pWindowless == NULL)
	{
		return TRUE; // no-op
	}

	if (prc)
	{
		return m_pWindowless->SetVideoPosition(NULL, prc);
	}
	else
	{
		RECT rc;
		GetClientRect(hwnd, &rc);
		return m_pWindowless->SetVideoPosition(NULL, &rc);
	}
}

BOOL CVMR7::Repaint(HWND hwnd, HDC hdc)
{
	if (m_pWindowless)
	{
		return m_pWindowless->RepaintVideo(hwnd, hdc);
	}
	else
	{
		return TRUE;
	}
}

BOOL CVMR7::DisplayModeChanged()
{
	if (m_pWindowless)
	{
		return m_pWindowless->DisplayModeChanged();
	}
	else
	{
		return TRUE;
	}
}


// Initialize the VMR-7 for windowless mode. 

BOOL InitWindowlessVMR(
	IBaseFilter *pVMR,              // Pointer to the VMR
	HWND hwnd,                      // Clipping window
	IVMRWindowlessControl** ppWC    // Receives a pointer to the VMR.
	)
{

	IVMRFilterConfig* pConfig = NULL;
	IVMRWindowlessControl *pWC = NULL;

	// Set the rendering mode.  
	BOOL hr = pVMR->QueryInterface(IID_PPV_ARGS(&pConfig));
	if (FAILED(hr))
	{
		goto done;
	}

	hr = pConfig->SetRenderingMode(VMRMode_Windowless);
	if (FAILED(hr))
	{
		goto done;
	}

	// Query for the windowless control interface.
	hr = pVMR->QueryInterface(IID_PPV_ARGS(&pWC));
	if (FAILED(hr))
	{
		goto done;
	}

	// Set the clipping window.
	hr = pWC->SetVideoClippingWindow(hwnd);
	if (FAILED(hr))
	{
		goto done;
	}

	// Preserve aspect ratio by letter-boxing
	hr = pWC->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);
	if (FAILED(hr))
	{
		goto done;
	}

	// Return the IVMRWindowlessControl pointer to the caller.
	*ppWC = pWC;
	(*ppWC)->AddRef();

done:
	SafeRelease(&pConfig);
	SafeRelease(&pWC);
	return hr;
}


/// VMR-9 Wrapper

CVMR9::CVMR9() : m_pWindowless(NULL)
{

}

BOOL CVMR9::HasVideo() const
{
	return (m_pWindowless != NULL);
}

CVMR9::~CVMR9()
{
	SafeRelease(&m_pWindowless);
}

BOOL CVMR9::AddToGraph(IGraphBuilder *pGraph, HWND hwnd)
{
	IBaseFilter *pVMR = NULL;

	BOOL hr = AddFilterByCLSID(pGraph, CLSID_VideoMixingRenderer9,
		&pVMR, L"VMR-9");
	if (SUCCEEDED(hr))
	{
		// Set windowless mode on the VMR. This must be done before the VMR 
		// is connected.
		hr = InitWindowlessVMR9(pVMR, hwnd, &m_pWindowless);
	}
	SafeRelease(&pVMR);
	return hr;
}

BOOL CVMR9::FinalizeGraph(IGraphBuilder *pGraph)
{
	if (m_pWindowless == NULL)
	{
		return TRUE;
	}

	IBaseFilter *pFilter = NULL;

	BOOL hr = m_pWindowless->QueryInterface(IID_PPV_ARGS(&pFilter));
	if (FAILED(hr))
	{
		goto done;
	}

	BOOL bRemoved;
	hr = RemoveUnconnectedRenderer(pGraph, pFilter, &bRemoved);

	// If we removed the VMR, then we also need to release our 
	// pointer to the VMR's windowless control interface.
	if (bRemoved)
	{
		SafeRelease(&m_pWindowless);
	}

done:
	SafeRelease(&pFilter);
	return hr;
}

BOOL CVMR9::UpdateVideoWindow(HWND hwnd, const LPRECT prc)
{
	if (m_pWindowless == NULL)
	{
		return TRUE; // no-op
	}

	if (prc)
	{
		return m_pWindowless->SetVideoPosition(NULL, prc);
	}
	else
	{

		RECT rc;
		GetClientRect(hwnd, &rc);
		return m_pWindowless->SetVideoPosition(NULL, &rc);
	}
}

BOOL CVMR9::Repaint(HWND hwnd, HDC hdc)
{
	if (m_pWindowless)
	{
		return m_pWindowless->RepaintVideo(hwnd, hdc);
	}
	else
	{
		return TRUE;
	}
}

BOOL CVMR9::DisplayModeChanged()
{
	if (m_pWindowless)
	{
		return m_pWindowless->DisplayModeChanged();
	}
	else
	{
		return TRUE;
	}
}


// Initialize the VMR-9 for windowless mode. 

BOOL InitWindowlessVMR9(
	IBaseFilter *pVMR,              // Pointer to the VMR
	HWND hwnd,                      // Clipping window
	IVMRWindowlessControl9** ppWC   // Receives a pointer to the VMR.
	)
{

	IVMRFilterConfig9 * pConfig = NULL;
	IVMRWindowlessControl9 *pWC = NULL;

	// Set the rendering mode.  
	BOOL hr = pVMR->QueryInterface(IID_PPV_ARGS(&pConfig));
	if (FAILED(hr))
	{
		goto done;
	}

	hr = pConfig->SetRenderingMode(VMR9Mode_Windowless);
	if (FAILED(hr))
	{
		goto done;
	}

	// Query for the windowless control interface.
	hr = pVMR->QueryInterface(IID_PPV_ARGS(&pWC));
	if (FAILED(hr))
	{
		goto done;
	}

	// Set the clipping window.
	hr = pWC->SetVideoClippingWindow(hwnd);
	if (FAILED(hr))
	{
		goto done;
	}

	// Preserve aspect ratio by letter-boxing
	hr = pWC->SetAspectRatioMode(VMR9ARMode_LetterBox);
	if (FAILED(hr))
	{
		goto done;
	}

	// Return the IVMRWindowlessControl pointer to the caller.
	*ppWC = pWC;
	(*ppWC)->AddRef();

done:
	SafeRelease(&pConfig);
	SafeRelease(&pWC);
	return hr;
}


/// EVR Wrapper

CEVR::CEVR() : m_pEVR(NULL), m_pVideoDisplay(NULL)
{

}

CEVR::~CEVR()
{
	SafeRelease(&m_pEVR);
	SafeRelease(&m_pVideoDisplay);
}

BOOL CEVR::HasVideo() const
{
	return (m_pVideoDisplay != NULL);
}

BOOL CEVR::AddToGraph(IGraphBuilder *pGraph, HWND hwnd)
{
	IBaseFilter *pEVR = NULL;

	BOOL hr = AddFilterByCLSID(pGraph, CLSID_EnhancedVideoRenderer,
		&pEVR, L"EVR");

	if (FAILED(hr))
	{
		goto done;
	}

	hr = InitializeEVR(pEVR, hwnd, &m_pVideoDisplay);
	if (FAILED(hr))
	{
		goto done;
	}

	// Note: Because IMFVideoDisplayControl is a service interface,
	// you cannot QI the pointer to get back the IBaseFilter pointer.
	// Therefore, we need to cache the IBaseFilter pointer.

	m_pEVR = pEVR;
	m_pEVR->AddRef();

done:
	SafeRelease(&pEVR);
	return hr;
}

BOOL CEVR::FinalizeGraph(IGraphBuilder *pGraph)
{
	if (m_pEVR == NULL)
	{
		return TRUE;
	}

	BOOL bRemoved;
	BOOL hr = RemoveUnconnectedRenderer(pGraph, m_pEVR, &bRemoved);
	if (bRemoved)
	{
		SafeRelease(&m_pEVR);
		SafeRelease(&m_pVideoDisplay);
	}
	return hr;
}

BOOL CEVR::UpdateVideoWindow(HWND hwnd, const LPRECT prc)
{
	if (m_pVideoDisplay == NULL)
	{
		return TRUE; // no-op
	}

	if (prc)
	{
		return m_pVideoDisplay->SetVideoPosition(NULL, prc);
	}
	else
	{

		RECT rc;
		GetClientRect(hwnd, &rc);
		return m_pVideoDisplay->SetVideoPosition(NULL, &rc);
	}
}

BOOL CEVR::Repaint(HWND hwnd, HDC hdc)
{
	if (m_pVideoDisplay)
	{
		return m_pVideoDisplay->RepaintVideo();
	}
	else
	{
		return TRUE;
	}
}

BOOL CEVR::DisplayModeChanged()
{
	// The EVR does not require any action in response to WM_DISPLAYCHANGE.
	return TRUE;
}


// Initialize the EVR filter. 

BOOL InitializeEVR(
	IBaseFilter *pEVR,              // Pointer to the EVR
	HWND hwnd,                      // Clipping window
	IMFVideoDisplayControl** ppDisplayControl
	)
{
	IMFGetService *pGS = NULL;
	IMFVideoDisplayControl *pDisplay = NULL;

	BOOL hr = pEVR->QueryInterface(IID_PPV_ARGS(&pGS));
	if (FAILED(hr))
	{
		goto done;
	}

	hr = pGS->GetService(MR_VIDEO_RENDER_SERVICE, IID_PPV_ARGS(&pDisplay));
	if (FAILED(hr))
	{
		goto done;
	}

	// Set the clipping window.
	hr = pDisplay->SetVideoWindow(hwnd);
	if (FAILED(hr))
	{
		goto done;
	}

	// Preserve aspect ratio by letter-boxing
	hr = pDisplay->SetAspectRatioMode(MFVideoARMode_PreservePicture);
	if (FAILED(hr))
	{
		goto done;
	}

	// Return the IMFVideoDisplayControl pointer to the caller.
	*ppDisplayControl = pDisplay;
	(*ppDisplayControl)->AddRef();

done:
	SafeRelease(&pGS);
	SafeRelease(&pDisplay);
	return hr;
}

// Helper functions.

BOOL RemoveUnconnectedRenderer(IGraphBuilder *pGraph, IBaseFilter *pRenderer, BOOL *pbRemoved)
{
	IPin *pPin = NULL;

	*pbRemoved = FALSE;

	// Look for a connected input pin on the renderer.

	BOOL hr = FindConnectedPin(pRenderer, PINDIR_INPUT, &pPin);
	SafeRelease(&pPin);

	// If this function succeeds, the renderer is connected, so we don't remove it.
	// If it fails, it means the renderer is not connected to anything, so
	// we remove it.

	if (FAILED(hr))
	{
		hr = pGraph->RemoveFilter(pRenderer);
		*pbRemoved = TRUE;
	}

	return hr;
}

BOOL IsPinConnected(IPin *pPin, BOOL *pResult)
{
	IPin *pTmp = NULL;
	BOOL hr = pPin->ConnectedTo(&pTmp);
	if (SUCCEEDED(hr))
	{
		*pResult = TRUE;
	}
	else if (hr == VFW_E_NOT_CONNECTED)
	{
		// The pin is not connected. This is not an error for our purposes.
		*pResult = FALSE;
		hr = TRUE;
	}

	SafeRelease(&pTmp);
	return hr;
}

BOOL IsPinDirection(IPin *pPin, PIN_DIRECTION dir, BOOL *pResult)
{
	PIN_DIRECTION pinDir;
	BOOL hr = pPin->QueryDirection(&pinDir);
	if (SUCCEEDED(hr))
	{
		*pResult = (pinDir == dir);
	}
	return hr;
}

BOOL FindConnectedPin(IBaseFilter *pFilter, PIN_DIRECTION PinDir,
	IPin **ppPin)
{
	*ppPin = NULL;

	IEnumPins *pEnum = NULL;
	IPin *pPin = NULL;

	BOOL hr = pFilter->EnumPins(&pEnum);
	if (FAILED(hr))
	{
		return hr;
	}

	BOOL bFound = FALSE;
	while (TRUE == pEnum->Next(1, &pPin, NULL))
	{
		BOOL bIsConnected;
		hr = IsPinConnected(pPin, &bIsConnected);
		if (SUCCEEDED(hr))
		{
			if (bIsConnected)
			{
				hr = IsPinDirection(pPin, PinDir, &bFound);
			}
		}

		if (FAILED(hr))
		{
			pPin->Release();
			break;
		}
		if (bFound)
		{
			*ppPin = pPin;
			break;
		}
		pPin->Release();
	}

	pEnum->Release();

	if (!bFound)
	{
		hr = VFW_E_NOT_FOUND;
	}
	return hr;
}

BOOL AddFilterByCLSID(IGraphBuilder *pGraph, REFGUID clsid,
	IBaseFilter **ppF, LPCWSTR wszName)
{
	*ppF = 0;

	IBaseFilter *pFilter = NULL;

	BOOL hr = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&pFilter));
	if (FAILED(hr))
	{
		goto done;
	}

	hr = pGraph->AddFilter(pFilter, wszName);
	if (FAILED(hr))
	{
		goto done;
	}

	*ppF = pFilter;
	(*ppF)->AddRef();

done:
	SafeRelease(&pFilter);
	return hr;
}