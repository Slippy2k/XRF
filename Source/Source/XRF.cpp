#include "PCH.h"
#include "XRF.h"

void PrintConsoleRevision()
{
	int regs[4];

	__cpuid(regs, CPUID_HW_REV);
	int consoleRevId = regs[2];

	char *consoleRev = (char *)calloc(1, 0x100);

	switch (consoleRevId)
	{
	case HW_REV_DURANGO:
		consoleRev = "Durango";
		break;
	case HW_REV_SILVERTON_ZORRO:
		consoleRev = "Silverton Zorro";
		break;
	case HW_REV_SILVERTON_MANDA:
		consoleRev = "Silverton Manda";
		break;
	case HW_REV_CARMEL_BASE:
		consoleRev = "Carmel Base";
		break;
	case HW_REV_CARMEL_4K:
		consoleRev = "Carmel 4K";
		break;
	case HW_REV_EDMONTON:
		consoleRev = "Edmonton";
		break;
	default:
		consoleRev = "Unknown";
	}
	printf("Console Revision: %s (0x%04X)\n", consoleRev, consoleRevId);
}

void PrintDevkitType()
{
	HANDLE hHandle = CreateFileA(
		PIPE_NAME_PSPSRA,
		GENERIC_READ | GENERIC_WRITE,
		OPEN_EXISTING,
		0,
		OPEN_EXISTING,
		0,
		NULL
	);

	if (hHandle == INVALID_HANDLE_VALUE) {
		printf("Could not get handle of %s\n", PIPE_NAME_PSPSRA);
		return;
	}

	DWORD read;
	LPVOID buf[SIZE_PSPSRA_CAPABILITES];
	BOOL ret = DeviceIoControl(
		hHandle,
		IOCTL_PIPE_PSPSRA_READ_CAPABILITIES,
		NULL,
		0,
		&buf,
		SIZE_PSPSRA_CAPABILITES,
		&read,
		NULL
	);

	if (!ret) {
		printf("READ_CAPABILITIES IOCTL failed!\n");
		return;
	}

	if (read != SIZE_PSPSRA_CAPABILITES) {
		printf("Invalid size console serial returned!\n Exp: %i - Got: %i\n",
			SIZE_PSPSRA_CAPABILITES,
			read
		);
		return;
	}

	UINT16 capabilities[0x100] = { 0 };
	memcpy(&capabilities, buf, 0x100);

	UINT16 cap = 0;
	char *flavour = (char *)calloc(1, 100);

	for (int i = 0; i < 0x100; i++) {
		cap = capabilities[i];
		switch (cap) {
		case DEVKIT_SRA:
			flavour = "DEVKIT SRA";
			break;
		case DEVKIT_ERA:
			flavour = "DEVKIT ERA";
			break;
		case DEVKIT_MS:
			flavour = "DEVKIT MS";
			break;
		case DEVKIT_SP:
			flavour = "DEVKIT SP";
			break;
		}
		if (strlen(flavour) > 0)
			break;
	}

	if (strlen(flavour) <= 0)
		flavour = "RETAIL";

	printf("Console Flavour: %s\n", flavour);
}
