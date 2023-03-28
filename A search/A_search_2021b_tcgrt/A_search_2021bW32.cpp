// ****************** A_search_2021bW32.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#include "TcPch.h"
#pragma hdrstop

#include "A_search_2021bCtrl.h"
#include "TcSysW32_i.c"

CComModule _Module;

const   CLSID   IID_A_search_2021bCtrl		=  {0x9386078E, 0x9714, 0x4C2A, {0xAA, 0xF1, 0x50, 0xB8, 0x94, 0x13, 0xDC, 0x84}};
const   CLSID   LIBID_A_search_2021bW32Lib	=  {0x5C43B918, 0x1D01, 0x41CC, {0xB3, 0x71, 0xA1, 0x86, 0x01, 0xB8, 0x6A, 0x87}};
const   CLSID   CLSID_A_search_2021bCtrl   =  {0xE519548D, 0x4F7B, 0x46D8, {0xAF, 0x40, 0xF0, 0x25, 0x94, 0xF1, 0x20, 0xC5}};

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_A_search_2021bCtrl, CA_search_2021bCtrl)
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

	CComObject<CA_search_2021bCtrl>* pCA_search_2021bCtrl = new CComObject<CA_search_2021bCtrl>();
	if (pCA_search_2021bCtrl == NULL) return E_POINTER;
	return pCA_search_2021bCtrl->QueryInterface(IID_ITcCtrl, reinterpret_cast<void**>(ppCtrl));
}