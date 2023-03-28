// ****************** A_SearchServices.h *************************
// Generated by TE140x-TargetForMatlabSimulink  2.3.1.1
// MATLAB 9.11.0.2022996 (R2021b) Update 4 (win64)
// TwinCAT 3.1.4024.0
// TwinCAT Target 2.3.1.1
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef _A_SearchServices__h_INCLUDED
#define _A_SearchServices__h_INCLUDED

#include "TcInterfaces.h"
#include "TcServices.h"
#include "TcGeneratedClass.h"
#include "TcGeneratedTcCom.h"
#include "stdio.h"

#include "TcGeneratedCFInterfaces.h"

#include "A_SearchVersion.h"
#define SRVNAME_A_Search "A_Search"

// TcCOM-ClassID of CTcComA_Search: {E8159DBE-F88B-7273-C6B3-6E0BE540CBDA}
const CTCID CID_A_SEARCH = {0xE8159DBE, 0xF88B, 0x7273, {0xC6, 0xB3, 0x6E, 0x0B, 0xE5, 0x40, 0xCB, 0xDA}};


#ifndef A_Search_IGNORE_SERVICES_TYPES
#if !defined(_TC_TYPE_C678E635_7635_0F31_42C4_7019C0FA0162_INCLUDED_)
#define _TC_TYPE_C678E635_7635_0F31_42C4_7019C0FA0162_INCLUDED_
typedef struct _A_Search_AdditionalInports
{
	bool TcModuleInput_enable;
	unsigned char reserved1[7];
	double TcModuleInput_endNode;
	double TcModuleInput_xRobotEnd;
	double TcModuleInput_xRobotStart;
	double TcModuleInput_yRobotEnd;
	double TcModuleInput_yRobotStart;
} A_Search_AdditionalInports, *PA_Search_AdditionalInports;
#endif // !defined(_TC_TYPE_C678E635_7635_0F31_42C4_7019C0FA0162_INCLUDED_)

#if !defined(_TC_TYPE_52DBFE87_3AFB_2D09_48C9_A9D296DAA97A_INCLUDED_)
#define _TC_TYPE_52DBFE87_3AFB_2D09_48C9_A9D296DAA97A_INCLUDED_
typedef double matrix_101x1_real_T[1][101];
#endif // !defined(_TC_TYPE_52DBFE87_3AFB_2D09_48C9_A9D296DAA97A_INCLUDED_)

#if !defined(_TC_TYPE_74EEF9C3_42A7_5DD1_FDA0_A5B31A364B13_INCLUDED_)
#define _TC_TYPE_74EEF9C3_42A7_5DD1_FDA0_A5B31A364B13_INCLUDED_
typedef struct _A_Search_AdditionalOutports
{
	matrix_101x1_real_T TcModuleOutput_xCoordinates;
	matrix_101x1_real_T TcModuleOutput_yCoordinates;
} A_Search_AdditionalOutports, *PA_Search_AdditionalOutports;
#endif // !defined(_TC_TYPE_74EEF9C3_42A7_5DD1_FDA0_A5B31A364B13_INCLUDED_)

#if !defined(_TC_TYPE_18071995_0000_0000_0000_00010000007F_INCLUDED_)
#define _TC_TYPE_18071995_0000_0000_0000_00010000007F_INCLUDED_
typedef CHAR STRING127[128];
#endif // !defined(_TC_TYPE_18071995_0000_0000_0000_00010000007F_INCLUDED_)

#if !defined(_TC_TYPE_A241177B_78D6_7DCE_7BE6_870A650A50EF_INCLUDED_)
#define _TC_TYPE_A241177B_78D6_7DCE_7BE6_870A650A50EF_INCLUDED_
typedef double matrix_101_real_T[101];
#endif // !defined(_TC_TYPE_A241177B_78D6_7DCE_7BE6_870A650A50EF_INCLUDED_)

#if !defined(_TC_TYPE_84F14F01_1544_F8A7_772F_08338F3898B9_INCLUDED_)
#define _TC_TYPE_84F14F01_1544_F8A7_772F_08338F3898B9_INCLUDED_
typedef double matrix_20736_real_T[20736];
#endif // !defined(_TC_TYPE_84F14F01_1544_F8A7_772F_08338F3898B9_INCLUDED_)

#if !defined(_TC_TYPE_96759023_969C_4C54_91CF_54C1F04F81ED_INCLUDED_)
#define _TC_TYPE_96759023_969C_4C54_91CF_54C1F04F81ED_INCLUDED_
typedef double matrix_12_real_T[12];
#endif // !defined(_TC_TYPE_96759023_969C_4C54_91CF_54C1F04F81ED_INCLUDED_)

#if !defined(_TC_TYPE_F943D866_5CCA_8252_A4DE_C3B2588A676E_INCLUDED_)
#define _TC_TYPE_F943D866_5CCA_8252_A4DE_C3B2588A676E_INCLUDED_
typedef double matrix_144_real_T[144];
#endif // !defined(_TC_TYPE_F943D866_5CCA_8252_A4DE_C3B2588A676E_INCLUDED_)

#if !defined(_TC_TYPE_EAB177BA_3216_3E2F_6CC4_294DE5D49ED8_INCLUDED_)
#define _TC_TYPE_EAB177BA_3216_3E2F_6CC4_294DE5D49ED8_INCLUDED_
typedef struct _B_A_Search_T
{
	double xRobotStart;
	double yRobotStart;
	double xRobotEnd;
	double yRobotEnd;
	double endNode;
	double startNode;
	matrix_101_real_T xKoordinaten;
	matrix_101_real_T yKoordinaten;
	matrix_101_real_T wayPointList;
	matrix_20736_real_T matrix;
	matrix_12_real_T removeNode;
	matrix_144_real_T xNode;
	matrix_144_real_T yNode;
	bool enable;
	unsigned char reserved1[7];
} B_A_Search_T, *PB_A_Search_T;
#endif // !defined(_TC_TYPE_EAB177BA_3216_3E2F_6CC4_294DE5D49ED8_INCLUDED_)


#endif

TCOM_DECL_INTERFACE("9379B375-26F9-13B0-F7DF-46BB4E9DF38E", ITcA_Search)



#endif // _A_SearchServices__h_INCLUDED