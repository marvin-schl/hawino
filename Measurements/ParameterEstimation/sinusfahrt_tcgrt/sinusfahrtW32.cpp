// ****************** sinusfahrtW32.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#include "TcPch.h"
#pragma hdrstop

#include "sinusfahrtCtrl.h"
#include "TcSysW32_i.c"

CComModule _Module;

const   CLSID   IID_sinusfahrtCtrl		=  {0xF79B3620, 0x1B53, 0x4B9B, {0xAF, 0x46, 0x08, 0xC6, 0x53, 0xE7, 0x4D, 0xEC}};
const   CLSID   LIBID_sinusfahrtW32Lib	=  {0xBE3042B7, 0x0DDD, 0x4DB8, {0x97, 0x05, 0x72, 0x35, 0x12, 0x4C, 0x0C, 0x3E}};
const   CLSID   CLSID_sinusfahrtCtrl   =  {0x544E7D42, 0x36A0, 0x4CA1, {0x85, 0x3B, 0x8D, 0x18, 0xCD, 0x3C, 0xEB, 0x0D}};

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_sinusfahrtCtrl, CsinusfahrtCtrl)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HANDLE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		_Module.Init(ObjectMap, (HINSTANCE)hInstance);
#ifndef UNDER_CE
		DisableThreadLibraryCalls((HINSTANCE)hInstance);
#endif
	}
	else if (dwReason == DLL_PROCESS_DETACH)
		_Module.Term();
	return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
	return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	// registers object, typelib and all interfaces in typelib
	return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	_Module.UnregisterServer();
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
STDAPI DllGetTcCtrl(ITcCtrl** ppCtrl)
{
	if ( ppCtrl == NULL )
		return E_POINTER;

	CComObject<CsinusfahrtCtrl>* pCsinusfahrtCtrl = new CComObject<CsinusfahrtCtrl>();
	if (pCsinusfahrtCtrl == NULL) return E_POINTER;
	return pCsinusfahrtCtrl->QueryInterface(IID_ITcCtrl, reinterpret_cast<void**>(ppCtrl));
}
