
// ****************** FbsimpleObserver.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************

#include "TcPch.h"
#pragma hdrstop

#include "FbsimpleObserver.h"

#include "simpleObserver.h"

#include "ObjClassFactory.h"
using namespace TcMgSdk;

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#if TC_BUILD<=4024
DEFINE_THIS_FILE()
#endif

///////////////////////////////////////////////////////////////////////////////
// CFbsimpleObserver specific globals
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CFbsimpleObserver static members
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CFbsimpleObserver implementation
///////////////////////////////////////////////////////////////////////////////
CFbsimpleObserver::CFbsimpleObserver()
{
	GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Init) = FpExcptCtrlSet::Prec53_CallerExceptions;
	GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Update) = FpExcptCtrlSet::Prec53_CallerExceptions;


	
}

CFbsimpleObserver::~CFbsimpleObserver()
{

}

bool CFbsimpleObserver::FB_Main()
{

	bool fbMainResult = true;

	

	auto fpState = FpControl(FpCtrlSection::Update);
	::simpleObserver_step();

	FpRestore(fpState);


	return fbMainResult;
}

void CFbsimpleObserver::_FB_Main(ST_FB_Main_FB_simpleObserver* ST_Param)
{
	ST_Param->result = ((CFbsimpleObserver*)ST_Param->pInst)->FB_Main(  );
}

bool CFbsimpleObserver::FB_exit(bool bInCopyCode)
{

	bool fbExitResult = true;

	auto fpState = FpControl(FpCtrlSection::Init);
	::simpleObserver_terminate();

	FpRestore(fpState);


	SingleInstanceRelease();
	__super::Exit(bInCopyCode);

	return fbExitResult;
}

void CFbsimpleObserver::_FB_exit(ST_FB_exit_FB_simpleObserver* ST_Param)
{
	ST_Param->result = ((CFbsimpleObserver*)ST_Param->pInst)->FB_exit( ST_Param->bInCopyCode );
}

bool CFbsimpleObserver::FB_init(bool bInitRetains, bool bInCopyCode)
{

	bool fbInitResult = true;

	if(fbInitResult)
	{
		memset(&(TcModuleInput_InCameraPose),0,sizeof(TcModuleInput_InCameraPose));
		memset(&(TcModuleInput_K),0,sizeof(TcModuleInput_K));
		memset(&(TcModuleOutput_DEBUG),0,sizeof(TcModuleOutput_DEBUG));
		memset(&(TcModuleOutput_Kout),0,sizeof(TcModuleOutput_Kout));
		memset(&(TcModuleOutput_OutEstimatedPose),0,sizeof(TcModuleOutput_OutEstimatedPose));
		memset(&(TcModuleOutput_version),0,sizeof(TcModuleOutput_version));
		TcModuleInput_InCameraPose[0] = 0;
		TcModuleInput_InCameraPose[1] = 0;
		TcModuleInput_InCameraPose[2] = 0;
		TcModuleInput_InVThetaworld = 0;
		TcModuleInput_InVXworld = 0;
		TcModuleInput_InVYworld = 0;
		TcModuleInput_K[0][0] = 1;
		TcModuleInput_K[0][1] = 0;
		TcModuleInput_K[0][2] = 0;
		TcModuleInput_K[1][0] = 0;
		TcModuleInput_K[1][1] = 1;
		TcModuleInput_K[1][2] = 0;
		TcModuleInput_K[2][0] = 0;
		TcModuleInput_K[2][1] = 0;
		TcModuleInput_K[2][2] = 1;
		TcModuleInput_omegaToRobot = 0;
		TcModuleInput_vxToRobot = 0;
		TcModuleInput_vyToRobot = 0;

		m_pData = nullptr;
		fbInitResult = __super::Init(0,TC_BUILD_MIN,bInitRetains,bInCopyCode);
		if (!fbInitResult)
		{
			error("__super::Init() did not succeed");
		}
	GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Init) = FpExcptCtrlSet::Prec53_CallerExceptions;
	GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Update) = FpExcptCtrlSet::Prec53_CallerExceptions;


	}

	fbInitResult &= SingleInstanceLock({0xC5732112, 0x3D51, 0xB549, {0x7F, 0xE5, 0xD8, 0x48, 0x2D, 0x01, 0xDF, 0xF2}});
	if(fbInitResult)
	{
		auto fpState = FpControl(FpCtrlSection::Init);
		::simpleObserver_initialize();
		simpleObserver_DW.InCameraPose_PWORK = reinterpret_cast<PVOID>(&(TcModuleInput_InCameraPose));
		simpleObserver_DW.InVThetaworld_PWORK = reinterpret_cast<PVOID>(&(TcModuleInput_InVThetaworld));
		simpleObserver_DW.InVXworld_PWORK = reinterpret_cast<PVOID>(&(TcModuleInput_InVXworld));
		simpleObserver_DW.InVYworld_PWORK = reinterpret_cast<PVOID>(&(TcModuleInput_InVYworld));
		simpleObserver_DW.K_PWORK = reinterpret_cast<PVOID>(&(TcModuleInput_K));
		simpleObserver_DW.omegaToRobot_PWORK = reinterpret_cast<PVOID>(&(TcModuleInput_omegaToRobot));
		simpleObserver_DW.vxToRobot_PWORK = reinterpret_cast<PVOID>(&(TcModuleInput_vxToRobot));
		simpleObserver_DW.vyToRobot_PWORK = reinterpret_cast<PVOID>(&(TcModuleInput_vyToRobot));
		simpleObserver_DW.DEBUG_PWORK = reinterpret_cast<PVOID>(&(TcModuleOutput_DEBUG));
		simpleObserver_DW.Kout_PWORK = reinterpret_cast<PVOID>(&(TcModuleOutput_Kout));
		simpleObserver_DW.OutEstimatedPose_PWORK = reinterpret_cast<PVOID>(&(TcModuleOutput_OutEstimatedPose));
		simpleObserver_DW.version_PWORK = reinterpret_cast<PVOID>(&(TcModuleOutput_version));

		FpRestore(fpState);
	}
	else
	{
		error("SingleInstanceLock() did not succeed");
	}

	return fbInitResult;
}

void CFbsimpleObserver::_FB_init(ST_FB_init_FB_simpleObserver* ST_Param)
{
	ST_Param->result = ((CFbsimpleObserver*)ST_Param->pInst)->FB_init( ST_Param->bInitRetains, ST_Param->bInCopyCode );
}




BEGIN_FUNC_MAP_FB(CFbsimpleObserver)
	FUNC_ENTRY_LIB(VID_simpleObserver, CID_FB_SIMPLEOBSERVER , "FB_simpleObserver" "__main", CFbsimpleObserver::_FB_Main)
FUNC_METHOD_ENTRY_LIB(VID_simpleObserver,CID_FB_SIMPLEOBSERVER , "FB_EXIT", "FB_simpleObserver" "__FB_exit", CFbsimpleObserver::_FB_exit)
FUNC_METHOD_ENTRY_LIB(VID_simpleObserver,CID_FB_SIMPLEOBSERVER , "FB_INIT", "FB_simpleObserver" "__FB_init", CFbsimpleObserver::_FB_init)

END_FUNC_MAP_FB()

DECLARE_FUNCMAP_CREATOR(HandleFuncMap_CFbsimpleObserver)
{
	return CFbsimpleObserver::TcHandleFuncMap(mode, idx, idxcounter, pFncId, pipFnc, ppMethod, ppName, pSignature, pVersion);
}
