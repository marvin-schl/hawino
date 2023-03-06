
// ****************** Fbsinusfahrt.h *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef _Fbsinusfahrt__h_INCLUDED
#define _Fbsinusfahrt__h_INCLUDED



#include "TcMatSimPou.h"
#include "TcGeneratedPou.h"
#include "sinusfahrtInternal.h"

#include "sinusfahrtDuts.h"
#include "sinusfahrtInterfaces.h"
#include "sinusfahrtVersion.h"

class CFbsinusfahrt :
	public TcMatSim::GeneratedPou
{
public:

	inline void operator()() {this->FB_Main();}
	inline GUID get_VersionID() {return VID_sinusfahrt;}
	inline CLSID get_ClassID() {return CID_FB_SINUSFAHRT;}

	DECLARE_FUNC_MAP_FB()

	CFbsinusfahrt();
	~CFbsinusfahrt();
	bool FB_Main();
	static void _FB_Main(ST_FB_Main_FB_sinusfahrt* ST_Param);
	bool FB_exit(bool bInCopyCode);
	static void _FB_exit(ST_FB_exit_FB_sinusfahrt* ST_Param);
	bool FB_init(bool bInitRetains, bool bInCopyCode);
	static void _FB_init(ST_FB_init_FB_sinusfahrt* ST_Param);


	double TcModuleOutput_vxSLX;
	PVOID Psinusfahrt_M;


};
TYPESIZE_VALIDATION2(CFbsinusfahrt,24,32);

			
#endif // _Fbsinusfahrt__h_INCLUDED
			