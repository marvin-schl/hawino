
// ****************** simpleObserverClassFactory.h *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef _simpleObserverClassFactory__h_INCLUDED
#define _simpleObserverClassFactory__h_INCLUDED

#include "TcMatSimCFServiceProvider.h"

class CsimpleObserverClassFactory : public CObjClassFactory
{
protected:
	DECLARE_REPOSITORY_DRIVER()
public:
	CsimpleObserverClassFactory();

	// ITComClassFactory
	DECLARE_CLASS_MAP()
	DECLARE_FUNC_MAP()

	DECLARE_MGCLASSFACTORY_CONNECT()
};

#endif // _simpleObserverClassFactory__h_INCLUDED
			