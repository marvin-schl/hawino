// ****************** KalmanObserver_R2021bDuts.h *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef _KalmanObserver_R2021bDuts__h_INCLUDED
#define _KalmanObserver_R2021bDuts__h_INCLUDED
#include "KalmanObserver_R2021bServices.h"

#if defined(_X86_)
typedef struct _ST_FB_init_FB_KalmanObserver_R2021b
{
	PVOID pInst;
	bool bInitRetains;
	bool bInCopyCode;
	bool result;
	unsigned char reserved1;
} ST_FB_init_FB_KalmanObserver_R2021b, *PST_FB_init_FB_KalmanObserver_R2021b;
#elif defined(_X64_)
typedef struct _ST_FB_init_FB_KalmanObserver_R2021b
{
	PVOID pInst;
	bool bInitRetains;
	bool bInCopyCode;
	bool result;
	unsigned char reserved1[5];
} ST_FB_init_FB_KalmanObserver_R2021b, *PST_FB_init_FB_KalmanObserver_R2021b;
#endif

#if defined(_X86_)
typedef struct _ST_FB_Main_FB_KalmanObserver_R2021b
{
	PVOID pInst;
	bool result;
	unsigned char reserved1[3];
} ST_FB_Main_FB_KalmanObserver_R2021b, *PST_FB_Main_FB_KalmanObserver_R2021b;
#elif defined(_X64_)
typedef struct _ST_FB_Main_FB_KalmanObserver_R2021b
{
	PVOID pInst;
	bool result;
	unsigned char reserved1[7];
} ST_FB_Main_FB_KalmanObserver_R2021b, *PST_FB_Main_FB_KalmanObserver_R2021b;
#endif

#if defined(_X86_)
typedef struct _ST_FB_exit_FB_KalmanObserver_R2021b
{
	PVOID pInst;
	bool bInCopyCode;
	bool result;
	unsigned char reserved1[2];
} ST_FB_exit_FB_KalmanObserver_R2021b, *PST_FB_exit_FB_KalmanObserver_R2021b;
#elif defined(_X64_)
typedef struct _ST_FB_exit_FB_KalmanObserver_R2021b
{
	PVOID pInst;
	bool bInCopyCode;
	bool result;
	unsigned char reserved1[6];
} ST_FB_exit_FB_KalmanObserver_R2021b, *PST_FB_exit_FB_KalmanObserver_R2021b;
#endif



#endif // _KalmanObserver_R2021bDuts__h_INCLUDED