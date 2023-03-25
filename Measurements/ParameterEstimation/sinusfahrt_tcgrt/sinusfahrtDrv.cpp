
// ****************** sinusfahrtDrv.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#include "TcPch.h"
#pragma hdrstop
#define DEVICE_MAIN

#include "sinusfahrtDrv.h"
#include "sinusfahrtClassFactory.h"
#include "sinusfahrtVersion.h"

DECLARE_GENERIC_DEVICE(sinusfahrtDRV)
#undef DEVICE_MAIN

IOSTATUS CsinusfahrtDrv::OnLoad( )
{
	TRACE(_T("CsinusfahrtClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CsinusfahrtClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CsinusfahrtDrv::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CsinusfahrtDrv::sinusfahrt_GetVersion( )
{
	return(0);
}