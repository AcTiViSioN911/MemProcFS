// m_modules.h : definitions related to initialization of built-in modules.
//
// (c) Ulf Frisk, 2018-2021
// Author: Ulf Frisk, pcileech@frizk.net
//
#ifndef __M_MODULES_H__
#define __M_MODULES_H__
#include <Windows.h>
#include "vmmdll.h"

/*
* Initialization function for the build-in virtual file system root folder module.
*/
VOID M_VfsRoot_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);

/*
* Initialization function for the build-in virtual file system process folder module.
*/
VOID M_VfsProc_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);

/*
* Initialization function for the build-in virtual file system forensic folder module.
*/
VOID M_VfsFc_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);

/*
* Initialization functions for ROOT modules.
* NB! modules may in some cases be combined ROOT/PROCESS modules.
*/
VOID M_FindEvil_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_Phys2Virt_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_Status_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_Sys_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_SysCert_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_SysDriver_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_SysMem_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pRI);
VOID M_SysNet_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_SysObj_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_SysProc_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_SysSvc_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_SysSyscall_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_Virt2Phys_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_WinReg_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);

/*
* Initialization functions for FORENSIC related modules.
*/
VOID M_FcTimeline_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_FcNtfs_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_FcProc_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_FcRegistry_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_FcThread_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);

/*
* Initialization functions for PROCESS related modules.
*/
VOID M_FileHandlesVads_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_FileModules_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_Handle_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_LdrModules_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_MemMap_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_MiniDump_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_ProcToken_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);
VOID M_Thread_Initialize(_Inout_ PVMMDLL_PLUGIN_REGINFO pPluginRegInfo);

VOID(*g_pfnModulesAllInternal[])(_In_ PVMMDLL_PLUGIN_REGINFO pRegInfo) = {
    // core modules
    M_VfsRoot_Initialize,
    M_VfsProc_Initialize,
    M_VfsFc_Initialize,
    // various per-process modules
    M_FileHandlesVads_Initialize,
    M_FileModules_Initialize,
    M_FindEvil_Initialize,
    M_Handle_Initialize,
    M_LdrModules_Initialize,
    M_MemMap_Initialize,
    M_MiniDump_Initialize,
    M_Phys2Virt_Initialize,
    M_ProcToken_Initialize,
    M_Thread_Initialize,
    M_Virt2Phys_Initialize,
    // various global modules
    M_Status_Initialize,
    M_Sys_Initialize,
    M_SysCert_Initialize,
    M_SysDriver_Initialize,
    M_SysMem_Initialize,
    M_SysNet_Initialize,
    M_SysObj_Initialize,
    M_SysProc_Initialize,
    M_SysSvc_Initialize,
    M_SysSyscall_Initialize,
    M_WinReg_Initialize,
    // various global forensic modules
    M_FcTimeline_Initialize,
    M_FcNtfs_Initialize,
    M_FcProc_Initialize,
    M_FcRegistry_Initialize,
    M_FcThread_Initialize,
};

#endif /* __M_MODULES_H__ */
