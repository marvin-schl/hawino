
// ****************** A_SearchDrv.h *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef _A_SearchDrv__h_INCLUDED
#define _A_SearchDrv__h_INCLUDED

#include "TcPch.h"

#define A_SearchDRV_NAME			"A_Search"
#define A_SearchDRV_Major			1
#define A_SearchDRV_Minor			0

#if defined DEVICE_MAIN		// is supposed to be __cplusplus

#define DEVICE_CLASS			CA_SearchDrv

#include "ObjDriver.h"

class CA_SearchDrv : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad( );
	virtual VOID		OnUnLoad( );
	
	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long _cdecl A_Search_GetVersion( );
};

#endif	// #if defined DEVICE_MAIN

Begin_VxD_Service_Table( A_SearchDRV)
	VxD_Service( A_Search_GetVersion		)
End_VxD_Service_Table


#endif // _A_SearchDrv__h_INCLUDED