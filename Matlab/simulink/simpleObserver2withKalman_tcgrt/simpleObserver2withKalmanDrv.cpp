
// ****************** simpleObserver2withKalmanDrv.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#include "TcPch.h"
#pragma hdrstop
#define DEVICE_MAIN

#include "simpleObserver2withKalmanDrv.h"
#include "simpleObserver2withKalmanClassFactory.h"
#include "simpleObserver2withKalmanVersion.h"

DECLARE_GENERIC_DEVICE(simpleObserver2withKalmanDRV)
#undef DEVICE_MAIN

IOSTATUS CsimpleObserver2withKalmanDrv::OnLoad( )
{
	TRACE(_T("CsimpleObserver2withKalmanClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CsimpleObserver2withKalmanClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CsimpleObserver2withKalmanDrv::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CsimpleObserver2withKalmanDrv::simpleObserver2withKalman_GetVersion( )
{
	return(0);
}