// ****************** simpleObserverServices.h *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef _simpleObserverServices__h_INCLUDED
#define _simpleObserverServices__h_INCLUDED

#include "TcInterfaces.h"
#include "TcServices.h"
#include "TcGeneratedClass.h"
#include "TcGeneratedTcCom.h"
#include "stdio.h"

#include "TcGeneratedCFInterfaces.h"

#include "simpleObserverVersion.h"
#define SRVNAME_simpleObserver "simpleObserver"

// TcCOM-ClassID of CTcComsimpleObserver: {7AF170C5-4C89-043A-5FA2-5E2CF044C0E3}
const CTCID CID_SIMPLEOBSERVER = {0x7AF170C5, 0x4C89, 0x043A, {0x5F, 0xA2, 0x5E, 0x2C, 0xF0, 0x44, 0xC0, 0xE3}};
// TcCOM-ClassID of CFbsimpleObserver: {A4FF6679-1B88-0E02-A1DC-1CEE34AE3822}
const CTCID CID_FB_SIMPLEOBSERVER = {0xA4FF6679, 0x1B88, 0x0E02, {0xA1, 0xDC, 0x1C, 0xEE, 0x34, 0xAE, 0x38, 0x22}};


#ifndef simpleObserver_IGNORE_SERVICES_TYPES
#if !defined(_TC_TYPE_610A2D24_A761_AE0B_B518_D70554B2A821_INCLUDED_)
#define _TC_TYPE_610A2D24_A761_AE0B_B518_D70554B2A821_INCLUDED_
typedef double matrix_3_real_T[3];
#endif // !defined(_TC_TYPE_610A2D24_A761_AE0B_B518_D70554B2A821_INCLUDED_)

#if !defined(_TC_TYPE_824D20A7_EC15_3B32_1649_6A6155D17982_INCLUDED_)
#define _TC_TYPE_824D20A7_EC15_3B32_1649_6A6155D17982_INCLUDED_
typedef struct _simpleObserver_AdditionalInports
{
	matrix_3_real_T TcModuleInput_InCameraPose;
	double TcModuleInput_InVThetaworld;
	double TcModuleInput_InVXworld;
	double TcModuleInput_InVYworld;
	double TcModuleInput_omegaToRobot;
	double TcModuleInput_vxToRobot;
	double TcModuleInput_vyToRobot;
} simpleObserver_AdditionalInports, *PsimpleObserver_AdditionalInports;
#endif // !defined(_TC_TYPE_824D20A7_EC15_3B32_1649_6A6155D17982_INCLUDED_)

#if !defined(_TC_TYPE_3D3E81F6_0331_CFE3_E6E1_0A2B65BB9859_INCLUDED_)
#define _TC_TYPE_3D3E81F6_0331_CFE3_E6E1_0A2B65BB9859_INCLUDED_
typedef struct _simpleObserver_AdditionalOutports
{
	double TcModuleOutput_DEBUG;
	matrix_3_real_T TcModuleOutput_OutEstimatedPose;
	double TcModuleOutput_version;
} simpleObserver_AdditionalOutports, *PsimpleObserver_AdditionalOutports;
#endif // !defined(_TC_TYPE_3D3E81F6_0331_CFE3_E6E1_0A2B65BB9859_INCLUDED_)

#if !defined(_TC_TYPE_72A91784_953A_FD09_4E66_5B1F6549B49B_INCLUDED_)
#define _TC_TYPE_72A91784_953A_FD09_4E66_5B1F6549B49B_INCLUDED_
typedef double matrix_9_real_T[9];
#endif // !defined(_TC_TYPE_72A91784_953A_FD09_4E66_5B1F6549B49B_INCLUDED_)

#if !defined(_TC_TYPE_0BACD104_E5F9_CCF2_8797_9495C4BBAEBD_INCLUDED_)
#define _TC_TYPE_0BACD104_E5F9_CCF2_8797_9495C4BBAEBD_INCLUDED_
typedef struct _P_simpleObserver_T
{
	double Constant_Value;
	double CameraDelay_InitialCondition;
	double DelayOneStep1_InitialCondition;
	double Integrator_IC;
	double Integrator_IC_i;
	matrix_9_real_T Gain_Gain;
} P_simpleObserver_T, *PP_simpleObserver_T;
#endif // !defined(_TC_TYPE_0BACD104_E5F9_CCF2_8797_9495C4BBAEBD_INCLUDED_)

#if !defined(_TC_TYPE_18071995_0000_0000_0000_00010000007F_INCLUDED_)
#define _TC_TYPE_18071995_0000_0000_0000_00010000007F_INCLUDED_
typedef CHAR STRING127[128];
#endif // !defined(_TC_TYPE_18071995_0000_0000_0000_00010000007F_INCLUDED_)

#if !defined(_TC_TYPE_D66A6CF3_92AF_F198_AE29_9C504D923AF2_INCLUDED_)
#define _TC_TYPE_D66A6CF3_92AF_F198_AE29_9C504D923AF2_INCLUDED_
typedef double matrix_42_real_T[42];
#endif // !defined(_TC_TYPE_D66A6CF3_92AF_F198_AE29_9C504D923AF2_INCLUDED_)

#if !defined(_TC_TYPE_E00C81F9_7F3B_CAE3_1D08_25CDC95DAF5C_INCLUDED_)
#define _TC_TYPE_E00C81F9_7F3B_CAE3_1D08_25CDC95DAF5C_INCLUDED_
typedef struct _simpleObserver_simpleObserver_DW1_Type
{
	matrix_42_real_T CameraDelay_DSTATE;
	matrix_3_real_T DelayOneStep1_DSTATE;
	matrix_3_real_T estPoseOld;
	matrix_3_real_T oldCamData;
} simpleObserver_simpleObserver_DW1_Type, *PsimpleObserver_simpleObserver_DW1_Type;
#endif // !defined(_TC_TYPE_E00C81F9_7F3B_CAE3_1D08_25CDC95DAF5C_INCLUDED_)


#endif

TCOM_DECL_INTERFACE("DF61D718-14E5-8E71-4F10-1DB6B66F66D0", ITcsimpleObserver)



#endif // _simpleObserverServices__h_INCLUDED