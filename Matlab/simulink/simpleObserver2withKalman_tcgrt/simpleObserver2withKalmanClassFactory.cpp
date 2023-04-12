
// ****************** simpleObserver2withKalmanClassFactory.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************

#include "TcPch.h"
#pragma hdrstop

#include "simpleObserver2withKalmanClassFactory.h"
#include "simpleObserver2withKalmanServices.h"
#include "TcGeneratedPou.h"

HRESULT TCOMAPI Create_CTcComsimpleObserver2withKalman (PITCID pIid, PPVOID pipItf);
DECLARE_FUNCMAP_CREATOR(HandleFuncMap_CFbsimpleObserver2withKalman);


DEFINE_REPOSITORY_DRIVER(CsimpleObserver2withKalmanClassFactory, simpleObserver2withKalman_LibraryIdNameStr)

// ITComClassFactory
BEGIN_CLASS_MAP(CsimpleObserver2withKalmanClassFactory)
	CLASS_ENTRY_LIB_RT_CREATOR(VID_simpleObserver2withKalman,CID_SIMPLEOBSERVER2WITHKALMAN, SRVNAME_simpleObserver2withKalman "!CTcComsimpleObserver2withKalman", Create_CTcComsimpleObserver2withKalman)

END_CLASS_MAP()

BEGIN_FUNC_MAP(CsimpleObserver2withKalmanClassFactory)
	FUNC_ENTRY_FB_CREATOR(HandleFuncMap_CFbsimpleObserver2withKalman)

END_FUNC_MAP()

CsimpleObserver2withKalmanClassFactory::CsimpleObserver2withKalmanClassFactory() : CObjClassFactory()
{
	#ifndef TC_USE_TMX_EXTENSION
		TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_simpleObserver2withKalman)); 
	#else
		TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME_TMX(SRVNAME_simpleObserver2withKalman));
	#if defined(TCDBG_UNIT_VERSION)
		TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(simpleObserver2withKalman));
	#endif //defined(TCDBG_UNIT_VERSION)
	#endif
}

IMPLEMENT_MGCLASSFACTORY_CONNECT(CsimpleObserver2withKalmanClassFactory,new TcMatSim::ServiceProvider(TC_BUILD_MIN))
			