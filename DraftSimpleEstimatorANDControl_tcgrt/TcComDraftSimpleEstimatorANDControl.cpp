// ****************** TcComDraftSimpleEstimatorANDControl.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#include "TcPch.h"
#pragma hdrstop

#include "TcComDraftSimpleEstimatorANDControl.h"

#ifdef EXT_MODE
#include "TcExtMode.h"
#include "TcExtWork.h"
#endif

#include "DraftSimpleEstimatorANDControl.h"

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
// CTcComDraftSimpleEstimatorANDControl specific globals
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CTcComDraftSimpleEstimatorANDControl static members
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CTcComDraftSimpleEstimatorANDControl implementation
///////////////////////////////////////////////////////////////////////////////
BEGIN_INTERFACE_MAP(CTcComDraftSimpleEstimatorANDControl)
INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcPersist,ITcPersist)
	INTERFACE_ENTRY(IID_ITComObject,ITComObject)
	INTERFACE_ENTRY(IID_ITcWatchSource,ITcWatchSource)
	INTERFACE_ENTRY(IID_ITcCyclic,ITcCyclic)
	INTERFACE_ENTRY(IID_ITcPostCyclic,ITcPostCyclic)
	INTERFACE_ENTRY(IID_ITcADI,ITcADI)
	INTERFACE_ENTRY(IID_ITcDraftSimpleEstimatorANDControl,ITcDraftSimpleEstimatorANDControl)
END_INTERFACE_MAP()

IMPLEMENT_ITCWATCHSOURCE(CTcComDraftSimpleEstimatorANDControl)

BEGIN_OBJDATAAREA_MAP(CTcComDraftSimpleEstimatorANDControl)
	OBJDATAAREA_SPAN_PTR_SIZE_FLAGS( 0, 1, &(AdditionalInports), sizeof(AdditionalInports), 0)
	OBJDATAAREA_SPAN_PTR_SIZE_FLAGS( 1, 1, &(AdditionalOutports), sizeof(AdditionalOutports), OBJDATAAREA_DISABLE_SET)
	OBJDATAAREA_SPAN_PTR_SIZE_FLAGS( 2, 1, PDraftSimpleEstimatorANDContr_M->blockIO, sizeof(*(PDraftSimpleEstimatorANDContr_M->blockIO)), OBJDATAAREA_DISABLE_SET)
	OBJDATAAREA_SPAN_PTR_SIZE_FLAGS( 3, 1, PDraftSimpleEstimatorANDContr_M->contStates, sizeof(*(PDraftSimpleEstimatorANDContr_M->contStates)), OBJDATAAREA_DISABLE_SET)
	OBJDATAAREA_SPAN_PTR_SIZE_FLAGS( 4, 1, &(PDraftSimpleEstimatorANDContr_M->dwork->DelayOneStep1_DSTATE), 408, OBJDATAAREA_DISABLE_SET)
END_OBJDATAAREA_MAP()

BEGIN_SETOBJPARA_MAP2(CTcComDraftSimpleEstimatorANDControl,TcMatSim::GeneratedTcCom)
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
	SETOBJPARA_VALUE_DENIED(0x0000000c,rtmGetT(PDraftSimpleEstimatorANDContr_M))
	SETOBJPARA_VALUE_DENIED(0x0000000d,&m_InitException)
	SETOBJPARA_VALUE_DENIED(0x0000000e,&m_ContextInfo[0].Execution.CycleCount)
	SETOBJPARA_VALUE_DENIED(0x0000000f,&m_ContextInfo[0].Execution.ExceptionCount)
	SETOBJPARA_VALUE_DENIED(0x00000010,&m_ContextInfo[0].Execution.ActException)
END_SETOBJPARA_MAP2(TcMatSim::GeneratedTcCom)

BEGIN_GETOBJPARA_MAP2(CTcComDraftSimpleEstimatorANDControl,TcMatSim::GeneratedTcCom)
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
	GETOBJPARA_VALUE_LOCK(0x0000000c, rtmGetT(PDraftSimpleEstimatorANDContr_M), 0, VarAccess(Access::None,Access::Read))
	GETOBJPARA_PTR_SIZE(0x0000000d,&m_InitException,sizeof(m_InitException))
	GETOBJPARA_PTR_SIZE(0x0000000e,&m_ContextInfo[0].Execution.CycleCount,sizeof(m_ContextInfo[0].Execution.CycleCount))
	GETOBJPARA_PTR_SIZE(0x0000000f,&m_ContextInfo[0].Execution.ExceptionCount,sizeof(m_ContextInfo[0].Execution.ExceptionCount))
	GETOBJPARA_PTR_SIZE(0x00000010,&m_ContextInfo[0].Execution.ActException,sizeof(m_ContextInfo[0].Execution.ActException))
END_GETOBJPARA_MAP2(TcMatSim::GeneratedTcCom)

BEGIN_OBJPARAWATCH_MAP2(CTcComDraftSimpleEstimatorANDControl)
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

IMPLEMENT_ITCADI(CTcComDraftSimpleEstimatorANDControl)

IMPLEMENT_IPERSIST_LIB(CTcComDraftSimpleEstimatorANDControl,VID_DraftSimpleEstimatorANDControl,CID_DRAFTSIMPLEESTIMATORANDCONTROL)

// State transition: Init -> PreOp
HRESULT CTcComDraftSimpleEstimatorANDControl::SetObjStateIP(ITComObjectServer* ipSrv, TComInitDataHdr* pInitData)
{
	HRESULT hr = S_OK;

	hr = SingleInstanceLock(ipSrv, GUID_NULL);
	if (SUCCEEDED(hr))
	{
		m_ContextInfo[0].OriginalTid = 0;
		m_ContextInfo[0].OriginalSampleTime = 0.01;

	}
	if (SUCCEEDED(hr))
	{
		PDraftSimpleEstimatorANDContr_M = ::DraftSimpleEstimatorANDControl();
		memset(&(AdditionalInports.TcModuleInput_InCameraPose),0,sizeof(AdditionalInports.TcModuleInput_InCameraPose));
		memset(&(AdditionalInports.TcModuleInput_InNextWaypoint),0,sizeof(AdditionalInports.TcModuleInput_InNextWaypoint));
		memset(&(AdditionalOutports.TcModuleOutput_Estimator1_vMotors),0,sizeof(AdditionalOutports.TcModuleOutput_Estimator1_vMotors));
		memset(&(AdditionalOutports.TcModuleOutput_Estimator1_vWorld),0,sizeof(AdditionalOutports.TcModuleOutput_Estimator1_vWorld));
		memset(&(AdditionalOutports.TcModuleOutput_OutDebugCase),0,sizeof(AdditionalOutports.TcModuleOutput_OutDebugCase));
		memset(&(AdditionalOutports.TcModuleOutput_OutErrorPose),0,sizeof(AdditionalOutports.TcModuleOutput_OutErrorPose));
		memset(&(AdditionalOutports.TcModuleOutput_OutEstTheta),0,sizeof(AdditionalOutports.TcModuleOutput_OutEstTheta));
		memset(&(AdditionalOutports.TcModuleOutput_OutEstX),0,sizeof(AdditionalOutports.TcModuleOutput_OutEstX));
		memset(&(AdditionalOutports.TcModuleOutput_OutEstY),0,sizeof(AdditionalOutports.TcModuleOutput_OutEstY));
		memset(&(AdditionalOutports.TcModuleOutput_OutVtoMotors),0,sizeof(AdditionalOutports.TcModuleOutput_OutVtoMotors));
		AdditionalInports.TcModuleInput_InCameraPose[0] = 0;
		AdditionalInports.TcModuleInput_InCameraPose[1] = 0;
		AdditionalInports.TcModuleInput_InCameraPose[2] = 0;
		AdditionalInports.TcModuleInput_InContrID = 0;
		AdditionalInports.TcModuleInput_InContrIN = 0;
		AdditionalInports.TcModuleInput_InContrP = 0;
		AdditionalInports.TcModuleInput_InContrlI = 0;
		AdditionalInports.TcModuleInput_InNextWaypoint[0] = 0;
		AdditionalInports.TcModuleInput_InNextWaypoint[1] = 0;
		AdditionalInports.TcModuleInput_InNextWaypoint[2] = 0;
		AdditionalInports.TcModuleInput_InVThetafromMotors = 0;
		AdditionalInports.TcModuleInput_InVXfromMotors = 0;
		AdditionalInports.TcModuleInput_InVYfromMotors = 0;

	}
	if (FAILED(hr))
	{
		SetObjStatePI();
	}
	return hr;
}

// State transition: PreOp -> SafeOp
HRESULT CTcComDraftSimpleEstimatorANDControl::SetObjStatePS(TComInitDataHdr* pInitData)
{
	HRESULT hr = S_OK;


	if(SUCCEEDED(hr))
	{
		auto fpState = FpControl(FpCtrlSection::Init);
		::DraftSimpleEstimatorANDControl_initialize(PDraftSimpleEstimatorANDContr_M);
		PDraftSimpleEstimatorANDContr_M->dwork->InCameraPose_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InCameraPose));
		PDraftSimpleEstimatorANDContr_M->dwork->InContrID_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InContrID));
		PDraftSimpleEstimatorANDContr_M->dwork->InContrIN_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InContrIN));
		PDraftSimpleEstimatorANDContr_M->dwork->InContrP_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InContrP));
		PDraftSimpleEstimatorANDContr_M->dwork->InContrlI_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InContrlI));
		PDraftSimpleEstimatorANDContr_M->dwork->InNextWaypoint_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InNextWaypoint));
		PDraftSimpleEstimatorANDContr_M->dwork->InVThetafromMotors_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InVThetafromMotors));
		PDraftSimpleEstimatorANDContr_M->dwork->InVXfromMotors_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InVXfromMotors));
		PDraftSimpleEstimatorANDContr_M->dwork->InVYfromMotors_PWORK = reinterpret_cast<PVOID>(&(AdditionalInports.TcModuleInput_InVYfromMotors));
		PDraftSimpleEstimatorANDContr_M->dwork->vMotors_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_Estimator1_vMotors));
		PDraftSimpleEstimatorANDContr_M->dwork->vWorld_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_Estimator1_vWorld));
		PDraftSimpleEstimatorANDContr_M->dwork->OutDebugCase_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_OutDebugCase));
		PDraftSimpleEstimatorANDContr_M->dwork->OutErrorPose_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_OutErrorPose));
		PDraftSimpleEstimatorANDContr_M->dwork->OutEstTheta_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_OutEstTheta));
		PDraftSimpleEstimatorANDContr_M->dwork->OutEstX_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_OutEstX));
		PDraftSimpleEstimatorANDContr_M->dwork->OutEstY_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_OutEstY));
		PDraftSimpleEstimatorANDContr_M->dwork->OutVtoMotors_PWORK = reinterpret_cast<PVOID>(&(AdditionalOutports.TcModuleOutput_OutVtoMotors));

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
HRESULT CTcComDraftSimpleEstimatorANDControl::SetObjStateSO()
{
	HRESULT hr = S_OK;

	if (FAILED(hr))
	{
		SetObjStateOS();
	}
	return hr;
}

// State transition: Op -> SafeOp
HRESULT CTcComDraftSimpleEstimatorANDControl::SetObjStateOS()
{
	HRESULT hr = S_OK;

	return hr;
}

// State transition: SafeOp -> PreOp
HRESULT CTcComDraftSimpleEstimatorANDControl::SetObjStateSP()
{
	HRESULT hr = S_OK;

	auto fpState = FpControl(FpCtrlSection::Init);
	FpRestore(fpState);

	m_Initialized = false;

	return hr;
}

// State transition: PreOp -> Init
HRESULT CTcComDraftSimpleEstimatorANDControl::SetObjStatePI()
{
	HRESULT hr = S_OK;

	auto fpState = FpControl(FpCtrlSection::Init);
	if (PDraftSimpleEstimatorANDContr_M!=NULL)
	{
		::DraftSimpleEstimatorANDControl_terminate(PDraftSimpleEstimatorANDContr_M);
		PDraftSimpleEstimatorANDContr_M = NULL;
	}

	FpRestore(fpState);
	SingleInstanceRelease();

	return hr;
}

// Constructor
CTcComDraftSimpleEstimatorANDControl::CTcComDraftSimpleEstimatorANDControl() :
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
CTcComDraftSimpleEstimatorANDControl::~CTcComDraftSimpleEstimatorANDControl()
{

}

HRESULT TCOMAPI CTcComDraftSimpleEstimatorANDControl::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
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

HRESULT TCOMAPI CTcComDraftSimpleEstimatorANDControl::PostCyclicUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
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

HRESULT CTcComDraftSimpleEstimatorANDControl::Update(ITcTask* ipTask, ULONG_PTR context)
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
			hr = EvalMdlErrorStatus(PDraftSimpleEstimatorANDContr_M->errorStatus,false);
			if (hr == S_OK)
			{
				::DraftSimpleEstimatorANDControl_step(PDraftSimpleEstimatorANDContr_M);
				EvalMdlErrorStatus(PDraftSimpleEstimatorANDContr_M->errorStatus,true);
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

HRESULT CTcComDraftSimpleEstimatorANDControl::CheckAndAdaptCycleTimes()
{
	double fCycleTimeMultiplier = 1;
	HRESULT hr = CheckCycleTimes(fCycleTimeMultiplier);
	if (SUCCEEDED(hr) && m_StepSizeAdaptation==TcMgSdk::StepSizeAdaptation::UseTaskCycleTime && fCycleTimeMultiplier != 1)
	{
		PDraftSimpleEstimatorANDContr_M->solverInfo->fixedStepSize *= fCycleTimeMultiplier;
		(*PDraftSimpleEstimatorANDContr_M->solverInfo->stepSizePtr) *= fCycleTimeMultiplier;
	}
	return hr;
}

// ITcDraftSimpleEstimatorANDControl
HRESULT TCOMAPI CTcComDraftSimpleEstimatorANDControl::DraftSimpleEstimatorANDControl_step()
{
	HRESULT hr = S_OK;
	auto fpState = FpControl(FpCtrlSection::Update);

	::DraftSimpleEstimatorANDControl_step(PDraftSimpleEstimatorANDContr_M);


	FpRestore(fpState);
	return hr;
}




HRESULT TCOMAPI Create_CTcComDraftSimpleEstimatorANDControl (PITCID pIid, PPVOID pipItf)
{
	return Create<CTcComDraftSimpleEstimatorANDControl>(*pIid, pipItf);
}
