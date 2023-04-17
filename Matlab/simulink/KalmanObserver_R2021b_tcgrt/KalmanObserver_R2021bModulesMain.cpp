
// dllmain.cpp : Defines the entry point for the DLL application.
#include "TcPch.h"
#pragma hdrstop

#include "TcBase.h"
#include "KalmanObserver_R2021bClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CKalmanObserver_R2021bCtrl  : public ITcOCFCtrlImpl< CKalmanObserver_R2021bCtrl, CKalmanObserver_R2021bClassFactory>
{
	public:
	CKalmanObserver_R2021bCtrl () {};
	virtual ~CKalmanObserver_R2021bCtrl() {};
};

// Default implementation for DllMain from TcFramework
BOOL DllMainImpl(HMODULE, DWORD, LPVOID);

// Entry point for loaders like FreeBSD in Kernel loader, which is
// operating on an already relocated DLL. For these loaders we need
// an explicitly "dllexported" symbol.
extern "C" __declspec(dllexport) BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	return DllMainImpl(hModule, ul_reason_for_call, lpReserved);
}

// Entry point for Windows loader (implicit lookup, not by name)
BOOL APIENTRY DllMainWin(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	return DllMain(hModule, ul_reason_for_call, lpReserved);
}

extern "C" __declspec(dllexport) HRESULT APIENTRY DllGetTcCtrl(ITcCtrl** ppTcCtrl)
{
	HRESULT hr = E_FAIL;
	TRACE("TcCM: DllGetTcCtrl(ITcCtrl** ppTcCtrl) \n");

	if (ppTcCtrl != NULL)
	{
		ITcCtrl* pTcCtrl = new IUnknownImpl<CKalmanObserver_R2021bCtrl>;
		pTcCtrl->AddRef();
		*ppTcCtrl = pTcCtrl;
		hr = S_OK;
	}
	else
	{
		hr = E_POINTER;
	}
	return hr;
}
			