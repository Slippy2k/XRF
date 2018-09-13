#include "PCH.h"
#include "XRF.h"

#define CMD_CONSOLE_INFO "cinfo"

int main(int argc, char *argv[])
{
	printf("[XRF] Hello!\n");

	if (argc < 2) {
		printf("[XRF] No parameters passed!\n\n");
		printf("[XRF] Commands: %s", CMD_CONSOLE_INFO);
		return 1;
	}

	if (strncmp(CMD_CONSOLE_INFO, argv[1], strlen(CMD_CONSOLE_INFO)) == 0) {
		PrintConsoleRevision();
		PrintDevkitType();
	}
	else {
		printf("[XRF] Unknown command passed.\n");
		return 2;
	}	

	return 0;
}
