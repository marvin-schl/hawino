##############################################################################
# Beckhoff Automation GmbH & Co. KG
# TwinCAT Target for MATLAB/Simulink
##############################################################################

#------------------------ system settings ------------------------------------
MSBUILDBINPATH = C:\Windows\Microsoft.NET\Framework\v4.0.30220
MODEL_NAME     = simpleObserver2withKalman
DEFINES_OTHER  = -DMODEL=simpleObserver2withKalman -DNUMST=2 -DNCSTATES=3 -DHAVESTDIO -DRT -DUSE_RTMODEL

#------------------------ model referencing ----------------------------------
MODELREFS                 = 
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = simpleObserver2withKalman_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..
MODELREF_TARGET_TYPE      = NONE
  
#------------------------ Macros read by TE1400_make -------------------------
MAKECMD         = nmake
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = TwinCatGrt.tlc

#------------------------- Main Make-Targets ----------------------------------
all: 
    @echo ### Created TwinCAT module source file for build with MSBUILD