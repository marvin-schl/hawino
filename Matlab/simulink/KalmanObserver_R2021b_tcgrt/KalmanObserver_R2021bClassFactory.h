
// ****************** KalmanObserver_R2021bClassFactory.h *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef _KalmanObserver_R2021bClassFactory__h_INCLUDED
#define _KalmanObserver_R2021bClassFactory__h_INCLUDED

#include "TcMatSimCFServiceProvider.h"

class CKalmanObserver_R2021bClassFactory : public CObjClassFactory
{
protected:
	DECLARE_REPOSITORY_DRIVER()
public:
	CKalmanObserver_R2021bClassFactory();

	// ITComClassFactory
	DECLARE_CLASS_MAP()
	DECLARE_FUNC_MAP()

	DECLARE_MGCLASSFACTORY_CONNECT()
};

#endif // _KalmanObserver_R2021bClassFactory__h_INCLUDED
			