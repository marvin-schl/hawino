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

const   CLSID   IID_A_search_2021bCtrl		=  {0x707A14D3, 0x8460, 0x488E, {0x97, 0x00, 0xB1, 0x44, 0x47, 0x6D, 0x3C, 0xEE}};
const   CLSID   LIBID_A_search_2021bW32Lib	=  {0x3DD4ADDD, 0xE2D7, 0x460C, {0x87, 0xF0, 0x3E, 0xA9, 0x45, 0xC9, 0x7B, 0xF9}};
const   CLSID   CLSID_A_search_2021bCtrl   =  {0x0B41297D, 0x8989, 0x4488, {0xAC, 0xF6, 0xD9, 0x12, 0x91, 0xE4, 0xD6, 0xDF}};

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
