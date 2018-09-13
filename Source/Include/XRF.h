#pragma once

/*
* Console CPUID
*/

#define CPUID_HW_REV 0x4000000D

/*
* Console Revisions (REQUIRES UPDATING)
*/

#define HW_REV_DURANGO             0x10
#define HW_REV_SILVERTON_ZORRO     0x20
#define HW_REV_SILVERTON_MANDA     0x21
#define HW_REV_CARMEL_BASE         0x30
#define HW_REV_CARMEL_4K           0x31
#define HW_REV_EDMONTON            0x40

/*
* Devkit types
*/

#define DEVKIT_SRA		0x2001
#define DEVKIT_ERA		0x4001
#define DEVKIT_MS		0x6001
#define DEVKIT_SP		0x8001


/*
* System pipes/drivers
*/

#define PIPE_NAME_PSPSRA					"\\\\.\\pspsra"
#define SIZE_PSPSRA_GEN_ECSDAP256			0x60
#define SIZE_PSPSRA_UNKNOWN_ODD				0x41C
#define SIZE_PSPSRA_DR0						0x20
#define SIZE_PSPSRA_CAPABILITES				0x200
#define SIZE_PSPSRA_CAPABILITY_DIGEST		0x140
#define SIZE_PSPSRA_XCONFIG_UNK				0x400
#define SIZE_PSPSRA_CONSOLESERIAL			0xC

#define IOCTL_PIPE_PSPSRA_GEN_ECSDAP256			0x22002C	//MsaDeviceExt.dll
#define IOCTL_PIPE_PSPSRA_UNKNOWN1				0x2200B0	// XUpdMgr.exe
#define IOCTL_PIPE_PSPSRA_UNKNOWN2				0x2200B4	// XUpdMgr.exe
#define IOCTL_PIPE_PSPSRA_UNKNOWN_ODD			0x2200D0	//AppServices.dll
#define IOCTL_PIPE_PSPSRA_INSTALL_AUXILARY		0x222004	//AppServices.dll
#define IOCTL_PIPE_PSPSRA_SYSTEM_VERSION		0x222008	//ShellCoreService.dll
#define IOCTL_PIPE_PSPSRA_UNKNOWN3				0x222070	// Xbox.Shell.Api
#define IOCTL_PIPE_PSPSRA_XCONFIG_POWER			0x222084	//Xbox.Shell.Api.dll
#define IOCTL_PIPE_PSPSRA_XCONFIG_UNK			0x22201C	// Xbox.Shell.Api.dll		
#define IOCTL_PIPE_PSPSRA_READ_DR0				0x222088	// xtfupdateT_s_i.dll
#define IOCTL_PIPE_PSPSRA_SP_INTERFACE_VER		0x221000	// XUpdMgr.exe
#define IOCTL_PIPE_PSPSRA_SP_REV_ID				0x221008	// XUpdMgr.exe
#define IOCTL_PIPE_PSPSRA_SP_OTHER				0x22100C	// XUpdMgr.exe
#define IOCTL_PIPE_PSPSRA_CONSOLESERIAL			0x221024	// ShellCoreService.dll
#define IOCTL_PIPE_PSPSRA_INIT_SP				0x221028	// XUpdMgr.exe
#define IOCTL_PIPE_PSPSRA_READ_CAPABILITIES		0x221034	// xtfupdateT_s_i.dll
#define IOCTL_PIPE_PSPSRA_READ_CAPABILITYDIGEST	0x221048	// xtfupdateT_s_i.dll
#define IOCTL_PIPE_PSPSRA_UNKNOWN4				0x22A033	// XupdMgr.exe
#define IOCTL_PIPE_PSPSRA_JUICY_1				0x221038	// XboxOneExtensions.dll

#define PIPE_NAME_XVUC						"\\\\.\\Xvuc"
#define SIZE_XVUC_SMC_FIRMWARE_ID			0x14
#define SIZE_XVUC_SB_REV					0x4
#define SIZE_XVUC_FACTORY_RESET				0x4
#define SIZE_XVUC_INIT						0x10
#define SIZE_XVUC_UNKNOWN_1					0x1
#define SIZE_XVUC_UNKNOWN_2					0x1
#define SIZE_XVUC_UNKNOWN_3					0x1
#define SIZE_XVUD_UNKNOWN_7					0x4
#define SIZE_XVUD_UNKNOWN_8					0x58

// XUpdMgr.exe -> sub_14001D0A4
#define IOCTL_PIPE_XVUC_UNKNOWN_1			0x0		// XUpdMgr.exe
#define IOCTL_PIPE_XVUC_UNKNOWN_6			0x14	// XUpdMgr.exe
#define IOCTL_PIPE_XVUC_UNKNOWN_2			0x18	// XUpdMgr.exe
#define IOCTL_PIPE_XVUC_SMC_FIRMWARE_ID		0x1E	// XUpdMgr.exe
#define IOCTL_PIPE_XVUD_UNKNOWN_8			0x2A	// XUpdMgr.exe
#define IOCTL_PIPE_XVUC_UNKNOWN_5			0x26	// XUpdMgr.exe
#define IOCTL_PIPE_XVUC_SB_REV				0x36	// XupdMgr.exe
#define IOCTL_PIPE_XVUC_UNKNOWN_3			0x39	// XUpdMgr.exe
#define IOCTL_PIPE_XVUC_FACTORY_RESET		0x3C	// XUpdMgr.exe
#define IOCTL_PIPE_XVUC_UNKNOWN_7			0x4E	// XUpdMgr.exe
#define IOCTL_PIPE_XVUC_UNKNOWN_4			0x226026	// xtfupdateT_s_i.dll

#define PIPE_NAME_ODD						"\\\\.\\O:"
#define SIZE_ODD_INFO						0x58
#define IOCTL_PIPE_ODD_GET_INFO				0x4D014		// AppServices.dll
#define IOCTL_PIPE_ODD_UNKNOWN				0x20040		// AppServices.dll


#define PIPE_NAME_ERACTRL					"\\\\.\\EraCtrl"
#define SIZE_ERACTRL_TOGGLE_PSTATE			0x4
#define IOCTL_PIPE_ERACTRL_UNKNOWN1			0x150114		// AppServices.dll
#define IOCTL_PIPE_ERACTRL_UNKNOWN2			0x150118		// AppServices.dll
#define IOCTL_PIPE_ERACTRL_TOGGLE_PSTATE	0x150140		// AppServices.dll
#define IOCTL_PIPE_ERACTRL_CONSOLEREGION	0x150148		// ShellCoreService.dll
#define IOCTL_PIPE_ERACTRL_POWER			0x1501BC

#define PIPE_NAME_XVIOC						"\\\\.\\XvioMonC"
#define IOCTL_PIPE_XVIOC_DEVKIT				0x1500A0		// Xbox.Shell.Api.dll
#define IOCTL_PIPE_XVIOC_ERA_CONTROL		0x1500A8
#define IOCTL_PIPE_XVIOC_ERA_RESTART		0x1500A4
#define IOCTL_PIPE_XVIOC_GET_STATUS			0x1500AC
#define IOCTL_PIPE_XVIOC_SET_FOCUS_VM		0x1500B0
#define IOCTL_PIPE_XVIOC_LAUNCH_APP			0x1500B4
#define IOCTL_PIPE_XVIOC_OS_INIT			0x1500BC
#define IOCTL_PIPE_XVIOC_QUERY_VMBOOTPERF	0x1500C4
#define IOCTL_PIPE_XVIOC_ENABLE_HVEC		0x1500CC
#define IOCTL_PIPE_XVIOC_SET_PSTATE			0x1500C8
#define IOCTL_PIPE_XVIOC_DISABLE_HVEC		0x1500D0

#define PIPE_NAME_XVUC_FLASH			"\\\\.\\Xvuc\\Flash"
#define PIPE_NAME_XVUC_FLASHFS			"\\\\.\\Xvuc\\FlashFs\\"

/*
* Common functions
*/

void PrintConsoleRevision();
void PrintDevkitType();
