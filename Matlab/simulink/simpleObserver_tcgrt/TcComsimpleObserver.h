// ****************** TcComsimpleObserver.h *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef _TcComsimpleObserver__h_INCLUDED
#define _TcComsimpleObserver__h_INCLUDED


#include "TcInterfaces.h"
#include "TcIoInterfaces.h"
#include "TcMatSimTcCom.h"
#include "simpleObserverInternal.h"

#include "simpleObserverInterfaces.h"
#include "simpleObserverVersion.h"


class CTcComsimpleObserver :
	public TcMatSim::GeneratedTcCom,
	public ITcWatchSource,
	public ITcCyclic,
	public ITcPostCyclic,
	public ITcADI,
	public ITcsimpleObserver
{
public:
	DECLARE_IUNKNOWN_DERIVED()
	DECLARE_ITCOMOBJECT_SETSTATE()
	DECLARE_ITCWATCHSOURCE()
	DECLARE_OBJDATAAREA_MAP()
	DECLARE_OBJPARAWATCH_MAP()
	DECLARE_PARA()
	DECLARE_ITCADI()
	DECLARE_IPERSIST_LIB()


	// Constructor
	CTcComsimpleObserver();

	// Destructor
	~CTcComsimpleObserver();

	HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);
	HRESULT TCOMAPI PostCyclicUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);
	HRESULT Update(ITcTask* ipTask, ULONG_PTR context);
	HRESULT CheckAndAdaptCycleTimes();

	// ITcsimpleObserver
	HRESULT TCOMAPI simpleObserver_step();



	simpleObserver_AdditionalInports AdditionalInports;
	simpleObserver_AdditionalOutports AdditionalOutports;



};
			

#endif // _TcComsimpleObserver__h_INCLUDED