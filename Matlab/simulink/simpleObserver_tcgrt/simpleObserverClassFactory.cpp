
// ****************** simpleObserverClassFactory.cpp *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************

#include "TcPch.h"
#pragma hdrstop

#include "simpleObserverClassFactory.h"
#include "simpleObserverServices.h"
#include "TcGeneratedPou.h"

HRESULT TCOMAPI Create_CTcComsimpleObserver (PITCID pIid, PPVOID pipItf);
DECLARE_FUNCMAP_CREATOR(HandleFuncMap_CFbsimpleObserver);


DEFINE_REPOSITORY_DRIVER(CsimpleObserverClassFactory, simpleObserver_LibraryIdNameStr)

// ITComClassFactory
BEGIN_CLASS_MAP(CsimpleObserverClassFactory)
	CLASS_ENTRY_LIB_RT_CREATOR(VID_simpleObserver,CID_SIMPLEOBSERVER, SRVNAME_simpleObserver "!CTcComsimpleObserver", Create_CTcComsimpleObserver)

END_CLASS_MAP()

BEGIN_FUNC_MAP(CsimpleObserverClassFactory)
	FUNC_ENTRY_FB_CREATOR(HandleFuncMap_CFbsimpleObserver)

END_FUNC_MAP()

CsimpleObserverClassFactory::CsimpleObserverClassFactory() : CObjClassFactory()
{
	#ifndef TC_USE_TMX_EXTENSION
		TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_simpleObserver)); 
	#else
		TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME_TMX(SRVNAME_simpleObserver));
	#if defined(TCDBG_UNIT_VERSION)
		TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(simpleObserver));
	#endif //defined(TCDBG_UNIT_VERSION)
	#endif
}

IMPLEMENT_MGCLASSFACTORY_CONNECT(CsimpleObserverClassFactory,new TcMatSim::ServiceProvider(TC_BUILD_MIN))
			