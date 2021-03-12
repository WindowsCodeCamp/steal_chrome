#include <stdio.h>
#include <string.h>
#include "chrome.h"

/*
	usage: steal_chrome.exe [--history] [--cookie] [--password]
*/

const char* usage = "usage: steal_chrome.exe [--history] [--cookie] [--password]";
int main(int argc, char* argv[])
{
	// Enum chrome profiles
	printf("Enum Chrome profile...\r\n");
	if (enum_chrome_profiles() == 0) {
		printf("Chrome profile NOT FOUND!");
		return 0;
	}

	if (argc == 1) {
		printf(usage);
		return 0;
	}

	int do_something = 0;
	for (int i = 1; i < argc; i++) {
		if (_stricmp(argv[i], "--history") == 0) {
			do_something++;
			// TODO get history
			continue;
		}
		if (_stricmp(argv[i], "--cookie") == 0) {
			do_something++;
			// TODO get cookie
			continue;
		}
		if (_stricmp(argv[i], "--password") == 0) {
			do_something++;
			// TODO get password
			continue;
		}
	}

	if (do_something == 0) {
		printf(usage);
		return 0;
	}
	return 0;
}
