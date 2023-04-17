
// ****************** KalmanObserver_R2021bClassFactory.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************

#include "TcPch.h"
#pragma hdrstop

#include "KalmanObserver_R2021bClassFactory.h"
#include "KalmanObserver_R2021bServices.h"
#include "TcGeneratedPou.h"

HRESULT TCOMAPI Create_CTcComKalmanObserver_R2021b (PITCID pIid, PPVOID pipItf);
DECLARE_FUNCMAP_CREATOR(HandleFuncMap_CFbKalmanObserver_R2021b);


DEFINE_REPOSITORY_DRIVER(CKalmanObserver_R2021bClassFactory, KalmanObserver_R2021b_LibraryIdNameStr)

// ITComClassFactory
BEGIN_CLASS_MAP(CKalmanObserver_R2021bClassFactory)
	CLASS_ENTRY_LIB_RT_CREATOR(VID_KalmanObserver_R2021b,CID_KALMANOBSERVER_R2021B, SRVNAME_KalmanObserver_R2021b "!CTcComKalmanObserver_R2021b", Create_CTcComKalmanObserver_R2021b)

END_CLASS_MAP()

BEGIN_FUNC_MAP(CKalmanObserver_R2021bClassFactory)
	FUNC_ENTRY_FB_CREATOR(HandleFuncMap_CFbKalmanObserver_R2021b)

END_FUNC_MAP()

CKalmanObserver_R2021bClassFactory::CKalmanObserver_R2021bClassFactory() : CObjClassFactory()
{
	#ifndef TC_USE_TMX_EXTENSION
		TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_KalmanObserver_R2021b)); 
	#else
		TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME_TMX(SRVNAME_KalmanObserver_R2021b));
	#if defined(TCDBG_UNIT_VERSION)
		TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(KalmanObserver_R2021b));
	#endif //defined(TCDBG_UNIT_VERSION)
	#endif
}

IMPLEMENT_MGCLASSFACTORY_CONNECT(CKalmanObserver_R2021bClassFactory,new TcMatSim::ServiceProvider(TC_BUILD_MIN))
			