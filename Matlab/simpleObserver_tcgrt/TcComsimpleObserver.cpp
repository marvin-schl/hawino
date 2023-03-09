// ****************** TcComsimpleObserver.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#include "TcPch.h"
#pragma hdrstop

#include "TcComsimpleObserver.h"

#ifdef EXT_MODE
#include "TcExtMode.h"
#include "TcExtWork.h"
#endif

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
// CTcComsimpleObserver specific globals
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CTcComsimpleObserver static members
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CTcComsimpleObserver implementation
///////////////////////////////////////////////////////////////////////////////
BEGIN_INTERFACE_MAP(CTcComsimpleObserver)
INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcPersist,ITcPersist)
	INTERFACE_ENTRY(IID_ITComObject,ITComObject)
	INTERFACE_ENTRY(IID_ITcWatchSource,ITcWatchSource)
	INTERFACE_ENTRY(IID_ITcCyclic,ITcCyclic)
	INTERFACE_ENTRY(IID_ITcPostCyclic,ITcPostCyclic)
	INTERFACE_ENTRY(IID_ITcADI,ITcADI)
	INTERFACE_ENTRY(IID_ITcsimpleObserver,ITcsimpleObserver)
END_INTERFACE_MAP()

IMPLEMENT_ITCWATCHSOURCE(CTcComsimpleObserver)

BEGIN_OBJDATAAREA_MAP(CTcComsimpleObserver)
	OBJDATAAREA_SPAN_PTR_SIZE_FLAGS( 0, 1, &(AdditionalInports), sizeof(AdditionalInports), 0)
	OBJDATAAREA_SPAN_PTR_SIZE_FLAGS( 1, 1, &(AdditionalOutports), sizeof(AdditionalOutports), OBJDATAAREA_DISABLE_SET)
	OBJDATAAREA_SPAN_PTR_SIZE_FLAGS( 2, 1, &(simpleObserver_P), sizeof(simpleObserver_P), 0)
	OBJDATAAREA_SPAN_PTR_SIZE_FLAGS( 3, 1, &(simpleObserver_DW.CameraDelay_DSTATE), 408, OBJDATAAREA_DISABLE_SET)
END_OBJDATAAREA_MAP()

BEGIN_SETOBJPARA_MAP2(CTcComsimpleObserver,TcMatSim::GeneratedTcCom)
	SETOBJPARA_DATAAREA_MAP()
	SETOBJPARA_VALUE(0x00000001,m_TraceLevelMax)
	SETOBJPARA_VALUE(0x00000002,m_ModuleCaller)
	SETOBJPARA_VALUE(0x00000003,m_CallerVerification)
	SETOBJPARA_VALUE(0x00000004,m_StepSizeAdaptation)
	SETOBJPARA_VALUE(0x00000005,m_ExecutionSequence)
	SETOBJPARA_VALUE(0x00000006,m_Execute)
	SETOBJPARA_VALUE(0x00000007,m_AccessLockState)
	SETOBJPARA_VALUE(0x00000008,GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Init))
	SETOBJPARA_VALUE(0x00000009,GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Update))
	SETOBJPARA_VALUE_DENIED(0x0000000a,m_ModuleBuildInfo)
	SETOBJPARA_VALUE_DENIED(0x0000000b,m_Initialized)
	SETOBJPARA_VALUE_DENIED(0x0000000c,rtmGetT(simpleObserver_M))
	SETOBJPARA_VALUE_DENIED(0x0000000d,&m_InitException)
	SETOBJPARA_VALUE_DENIED(0x0000000e,&m_ContextInfo[0].Execution.CycleCount)
	SETOBJPARA_VALUE_DENIED(0x0000000f,&m_ContextInfo[0].Execution.ExceptionCount)
	SETOBJPARA_VALUE_DENIED(0x00000010,&m_ContextInfo[0].Execution.ActException)
END_SETOBJPARA_MAP2(TcMatSim::GeneratedTcCom)

BEGIN_GETOBJPARA_MAP2(CTcComsimpleObserver,TcMatSim::GeneratedTcCom)
	GETOBJPARA_DATAAREA_MAP()
	GETOBJPARA_VALUE(0x00000001,m_TraceLevelMax)
	GETOBJPARA_VALUE(0x00000002,m_ModuleCaller)
	GETOBJPARA_VALUE(0x00000003,m_CallerVerification)
	GETOBJPARA_VALUE(0x00000004,m_StepSizeAdaptation)
	GETOBJPARA_VALUE(0x00000005,m_ExecutionSequence)
	GETOBJPARA_VALUE(0x00000006,m_Execute)
	GETOBJPARA_VALUE(0x00000007,m_AccessLockState)
	GETOBJPARA_VALUE(0x00000008,GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Init))
	GETOBJPARA_VALUE(0x00000009,GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Update))
	GETOBJPARA_VALUE(0x0000000a,m_ModuleBuildInfo)
	GETOBJPARA_VALUE(0x0000000b,m_Initialized)
	GETOBJPARA_VALUE_LOCK(0x0000000c, rtmGetT(simpleObserver_M), 0, VarAccess(Access::None,Access::Read))
	GETOBJPARA_PTR_SIZE(0x0000000d,&m_InitException,sizeof(m_InitException))
	GETOBJPARA_PTR_SIZE(0x0000000e,&m_ContextInfo[0].Execution.CycleCount,sizeof(m_ContextInfo[0].Execution.CycleCount))
	GETOBJPARA_PTR_SIZE(0x0000000f,&m_ContextInfo[0].Execution.ExceptionCount,sizeof(m_ContextInfo[0].Execution.ExceptionCount))
	GETOBJPARA_PTR_SIZE(0x00000010,&m_ContextInfo[0].Execution.ActException,sizeof(m_ContextInfo[0].Execution.ActException))
END_GETOBJPARA_MAP2(TcMatSim::GeneratedTcCom)

BEGIN_OBJPARAWATCH_MAP2(CTcComsimpleObserver)
	OBJPARAWATCH_DATAAREA_MAP()
	OBJPARAWATCH_VALUE(0x00000001,m_TraceLevelMax)
	OBJPARAWATCH_VALUE(0x00000002,m_ModuleCaller)
	OBJPARAWATCH_VALUE(0x00000003,m_CallerVerification)
	OBJPARAWATCH_VALUE(0x00000004,m_StepSizeAdaptation)
	OBJPARAWATCH_VALUE(0x00000005,m_ExecutionSequence)
	OBJPARAWATCH_VALUE(0x00000006,m_Execute)
	OBJPARAWATCH_VALUE(0x00000007,m_AccessLockState)
	OBJPARAWATCH_VALUE(0x00000008,GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Init))
	OBJPARAWATCH_VALUE(0x00000009,GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Update))
	OBJPARAWATCH_VALUE(0x0000000a,m_ModuleBuildInfo)
	OBJPARAWATCH_VALUE(0x0000000b,m_Initialized)
	OBJPARAWATCH_PTR_SIZE(0x0000000d,&m_InitException,sizeof(m_InitException))
	OBJPARAWATCH_PTR_SIZE(0x0000000e,&m_ContextInfo[0].Execution.CycleCount,sizeof(m_ContextInfo[0].Execution.CycleCount))
	OBJPARAWATCH_PTR_SIZE(0x0000000f,&m_ContextInfo[0].Execution.ExceptionCount,sizeof(m_ContextInfo[0].Execution.ExceptionCount))
	OBJPARAWATCH_PTR_SIZE(0x00000010,&m_ContextInfo[0].Execution.ActException,sizeof(m_ContextInfo[0].Execution.ActException))
END_OBJPARAWATCH_MAP2(TcMatSim::GeneratedTcCom)

IMPLEMENT_ITCADI(CTcComsimpleObserver)

IMPLEMENT_IPERSIST_LIB(CTcComsimpleObserver,VID_simpleObserver,CID_SIMPLEOBSERVER)

// State transition: Init -> PreOp
HRESULT CTcComsimpleObserver::SetObjStateIP(ITComObjectServer* ipSrv, TComInitDataHdr* pInitData)
{
	HRESULT hr = S_OK;

	hr = SingleInstanceLock(ipSrv, {0xC5732112, 0x3D51, 0xB549, {0x7F, 0xE5, 0xD8, 0x48, 0x2D, 0x01, 0xDF, 0xF2}});
	if (SUCCEEDED(hr))
	{
		m_ContextInfo[0].OriginalTid = 0;
		m_ContextInfo[0].OriginalSampleTime = 0.01;

	}
	if (SUCCEEDED(hr))
	{
		memset(&(AdditionalInports.TcModuleInput_InCameraPose),0,sizeof(AdditionalInports.TcModuleInput_InCameraPose));
		memset(&(AdditionalInports.TcModuleInput_K),0,sizeof(AdditionalInports.TcModuleInput_K));
		memset(&(AdditionalOutports.TcModuleOutput_DEBUG),0,sizeof(AdditionalOutports.TcModuleOutput_DEBUG));
		memset(&(AdditionalOutports.TcModuleOutput_Kout),0,sizeof(AdditionalOutports.TcModuleOutput_Kout));
		memset(&(AdditionalOutports.TcModuleOutput_OutEstimatedPose),0,sizeof(AdditionalOutports.TcModuleOutput_OutEstimatedPose));
		memset(&(AdditionalOutports.TcModuleOutput_version),0,sizeof(AdditionalOutports.TcModuleOutput_version));
		AdditionalInports.TcModuleInput_InCameraPose[0] = 0;
		AdditionalInports.TcModuleInput_InCameraPose[1] = 0;
		AdditionalInports.TcModuleInput_InCameraPose[2] = 0;
		AdditionalInports.TcModuleInput_InVThetaworld = 0;
		AdditionalInports.TcModuleInput_InVXworld = 0;
		AdditionalInports.TcModuleInput_InVYworld = 0;
		AdditionalInports.TcModuleInput_K[0][0] = 1;
		AdditionalInports.TcModuleInput_K[0][1] = 0;
		AdditionalInports.TcModuleInput_K[0][2] = 0;
		AdditionalInports.TcModuleInput_K[1][0] = 0;
		AdditionalInports.TcModuleInput_K[1][1] = 1;
		AdditionalInports.TcModuleInput_K[1][2] = 0;
		AdditionalInports.TcModuleInput_K[2][0] = 0;
		AdditionalInports.TcModuleInput_K[2][1] = 0;
		AdditionalInports.TcModuleInput_K[2][2] = 1;
		AdditionalInports.TcModuleInput_omegaToRobot = 0;
		AdditionalInports.TcModuleInput_vxToRobot = 0;
		AdditionalInports.TcModuleInput_vyToRobot = 0;

	}
	if (FAILED(hr))
	{
		SetObjStatePI();
	}
	return hr;
}

// State transition: PreOp -> SafeOp
HRESULT CTcComsimpleObserver::SetObjStatePS(TComInitDataHdr* pInitData)
{
	HRESULT hr = S_OK;


	if(SUCCEEDED(hr))
	{
		auto fpState = FpControl(FpCtrlSection::Init);
		::simpleObserver_initialize();
		simpleObserver_DW.InCameraPose_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InCameraPose));
		simpleObserver_DW.InVThetaworld_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InVThetaworld));
		simpleObserver_DW.InVXworld_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InVXworld));
		simpleObserver_DW.InVYworld_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InVYworld));
		simpleObserver_DW.K_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_K));
		simpleObserver_DW.omegaToRobot_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_omegaToRobot));
		simpleObserver_DW.vxToRobot_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_vxToRobot));
		simpleObserver_DW.vyToRobot_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_vyToRobot));
		simpleObserver_DW.DEBUG_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_DEBUG));
		simpleObserver_DW.Kout_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_Kout));
		simpleObserver_DW.OutEstimatedPose_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_OutEstimatedPose));
		simpleObserver_DW.version_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_version));

		if (SUCCEEDED(hr))
			hr = CheckAndAdaptCycleTimes();
		m_Initialized = SUCCEEDED(hr);
		FpRestore(fpState);
	}

	if (FAILED(hr))
	{
		SetObjStateSP();
	}
	return hr;
}

// State transition: SafeOp -> Op
HRESULT CTcComsimpleObserver::SetObjStateSO()
{
	HRESULT hr = S_OK;

	if (FAILED(hr))
	{
		SetObjStateOS();
	}
	return hr;
}

// State transition: Op -> SafeOp
HRESULT CTcComsimpleObserver::SetObjStateOS()
{
	HRESULT hr = S_OK;

	return hr;
}

// State transition: SafeOp -> PreOp
HRESULT CTcComsimpleObserver::SetObjStateSP()
{
	HRESULT hr = S_OK;

	auto fpState = FpControl(FpCtrlSection::Init);
	FpRestore(fpState);

	m_Initialized = false;

	return hr;
}

// State transition: PreOp -> Init
HRESULT CTcComsimpleObserver::SetObjStatePI()
{
	HRESULT hr = S_OK;

	auto fpState = FpControl(FpCtrlSection::Init);
	::simpleObserver_terminate();

	FpRestore(fpState);
	SingleInstanceRelease();

	return hr;
}

// Constructor
CTcComsimpleObserver::CTcComsimpleObserver() :
	TcMatSim::GeneratedTcCom(1,0,TC_BUILD_MIN)
{
	m_TraceLevelMax = tlInfo;
	m_ModuleCaller = ModuleCaller::CyclicTask;
	m_CallerVerification = CallerVerification::Default;
	m_StepSizeAdaptation = StepSizeAdaptation::RequireMatchingTaskCycleTime;
	m_ExecutionSequence = ExecutionSequence2::UpdateBeforeOutputMapping;
	m_Execute = false;
	m_AccessLockState = TCOM_STATE_OP;
	GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Init) = FpExcptCtrlSet::Prec53_CallerExceptions;
	GetFpExceptCtrlSet(TcMgSdk::FpCtrlSection::Update) = FpExcptCtrlSet::Prec53_CallerExceptions;
	m_Initialized = 0;

#ifdef _DEBUG
	m_ModuleBuildInfo.Debug = true;
#else
	m_ModuleBuildInfo.Debug = false;
#endif
	m_ModuleBuildInfo.TcBuild = TC_BUILD;
	m_ModuleBuildInfo.TcRevision = TC_REVISION;

}

// Destructor
CTcComsimpleObserver::~CTcComsimpleObserver()
{

}

HRESULT TCOMAPI CTcComsimpleObserver::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{

	if (!m_Execute)
		return S_FALSE;
	if (!m_Initialized)
		return ADS_E_NOTINIT;
	if (m_ExecutionSequence!=TcMgSdk::ExecutionSequence2::UpdateBeforeOutputMapping)
		return S_OK;
	m_ContextInfo[context].ExecutingCyclicCall = true;
	HRESULT hr = Update(ipTask, context);
	m_ContextInfo[context].ExecutingCyclicCall = false;
	return hr;
}

HRESULT TCOMAPI CTcComsimpleObserver::PostCyclicUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{

	if (!m_Execute)
		return S_FALSE;
	if (!m_Initialized)
		return ADS_E_NOTINIT;
	if (m_ExecutionSequence!=TcMgSdk::ExecutionSequence2::IoAtTaskBegin)
		return S_OK;
	m_ContextInfo[context].ExecutingPostCyclicCall = true;
	HRESULT hr = Update(ipTask, context);
	m_ContextInfo[context].ExecutingPostCyclicCall = false;
	return hr;
}

HRESULT CTcComsimpleObserver::Update(ITcTask* ipTask, ULONG_PTR context)
{
	HRESULT hr = SynchronizeTasks(context);
	if(SUCCEEDED(hr))
		hr = VerifyCaller(ipTask, context);

	if(SUCCEEDED(hr) && m_ContextInfo[context].Synchronized)
	{
		m_ContextInfo[context].Execution.CycleCount++;
		auto fpState = FpControl(FpCtrlSection::Update);
		TcTry
		{
			hr = EvalMdlErrorStatus(simpleObserver_M->errorStatus,false);
			if (hr == S_OK)
			{
				::simpleObserver_step();
				EvalMdlErrorStatus(simpleObserver_M->errorStatus,true);
			}

		}
		TcExcept(ExceptionFilter(ipTask, GetExceptionInformation(), static_cast<LONG>(context), &m_Execute))
		{
			m_Execute = false;
			m_Initialized = false;
			m_Trace.Log(TcTraceLevel::tlError,"%s: Stopping cyclic execution of model code due to an exception. Module reinitialization is required.", m_objName.str);
		}
		FpRestore(fpState);
	}

	return hr;

}

HRESULT CTcComsimpleObserver::CheckAndAdaptCycleTimes()
{
	double fCycleTimeMultiplier = 1;
	HRESULT hr = CheckCycleTimes(fCycleTimeMultiplier);
	if (SUCCEEDED(hr) && m_StepSizeAdaptation==TcMgSdk::StepSizeAdaptation::UseTaskCycleTime && fCycleTimeMultiplier != 1)
	{
		simpleObserver_M->solverInfo.fixedStepSize *= fCycleTimeMultiplier;
		(*simpleObserver_M->solverInfo.stepSizePtr) *= fCycleTimeMultiplier;
	}
	return hr;
}

// ITcsimpleObserver
HRESULT TCOMAPI CTcComsimpleObserver::simpleObserver_step()
{
	HRESULT hr = S_OK;
	auto fpState = FpControl(FpCtrlSection::Update);

	::simpleObserver_step();


	FpRestore(fpState);
	return hr;
}




HRESULT TCOMAPI Create_CTcComsimpleObserver (PITCID pIid, PPVOID pipItf)
{
	return Create<CTcComsimpleObserver>(*pIid, pipItf);
}
