
// ****************** A_searchDrv.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#include "TcPch.h"
#pragma hdrstop
#define DEVICE_MAIN

#include "A_searchDrv.h"
#include "A_searchClassFactory.h"
#include "A_searchVersion.h"

DECLARE_GENERIC_DEVICE(A_searchDRV)
#undef DEVICE_MAIN

IOSTATUS CA_searchDrv::OnLoad( )
{
	TRACE(_T("CA_searchClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CA_searchClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CA_searchDrv::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CA_searchDrv::A_search_GetVersion( )
{
	return(0);
}