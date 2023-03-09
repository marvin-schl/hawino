
// ****************** simpleObserverCtrl.h *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef _simpleObserverCtrl__h_INCLUDED
#define _simpleObserverCtrl__h_INCLUDED

#include <atlbase.h>
#include <atlcom.h>

#define CsimpleObserverDrvName "simpleObserver"

#include "simpleObserverW32Resource.h"
#include "simpleObserverW32.h"
#include "TcPch.h"
#pragma hdrstop

#include "simpleObserverClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CsimpleObserverCtrl :	public CComObjectRootEx<CComMultiThreadModel>
							, public CComCoClass<CsimpleObserverCtrl, &CLSID_TcRtwDriverCtrl>
							, public ITcRtwDriverCtrl
							, public ITcOCFCtrlImpl<CsimpleObserverCtrl, CsimpleObserverClassFactory>
{
public:
	CsimpleObserverCtrl() : ITcOCFCtrlImpl<CsimpleObserverCtrl, CsimpleObserverClassFactory>(){}

	virtual ~CsimpleObserverCtrl() {}


DECLARE_REGISTRY_RESOURCEID(IDR_simpleObserverCtrl)
DECLARE_NOT_AGGREGATABLE(CsimpleObserverCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CsimpleObserverCtrl)
	COM_INTERFACE_ENTRY(ITcRtwDriverCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // _simpleObserverCtrl__h_INCLUDED