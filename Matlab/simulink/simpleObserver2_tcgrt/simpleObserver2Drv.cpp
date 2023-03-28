
// ****************** simpleObserver2Drv.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#include "TcPch.h"
#pragma hdrstop
#define DEVICE_MAIN

#include "simpleObserver2Drv.h"
#include "simpleObserver2ClassFactory.h"
#include "simpleObserver2Version.h"

DECLARE_GENERIC_DEVICE(simpleObserver2DRV)
#undef DEVICE_MAIN

IOSTATUS CsimpleObserver2Drv::OnLoad( )
{
	TRACE(_T("CsimpleObserver2ClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CsimpleObserver2ClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CsimpleObserver2Drv::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CsimpleObserver2Drv::simpleObserver2_GetVersion( )
{
	return(0);
}