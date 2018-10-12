#include <cstdio>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <experimental/filesystem>
#include <limits.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <stdlib.h>

int KernelDirectorySpookiness = 0;
int NumberOfThreads = 0;
int CheckInput = -99;
int SkipMode = 0;
const char *BasicMake = "sudo make -j";
const char *BasicMakeInstall = "sudo make install -j";
const char *BasicMakeModulesInstall = "sudo make modules_install -j";
const char *BasicMakeModules = "sudo make modules -j";
const char *LowPerfMake = "sudo make";
const char *LowPerfMakeInstall = "sudo make install";
const char *LowPerfMakeModulesInstall = "sudo make modules_install";
const char *LowPerfMakeModules = "sudo make modules";
const char *HighPerfMake = "sudo make -j";
const char *HighPerfMakeInstall = "sudo make install -j";
const char *HighPerfMakeModulesInstall = "sudo make modules_install -j";
const char *HighPerfMakeModules = "sudo make modules -j";

int main(int argc, char *argv[])
{
	// Hidden command to stop segfault
	// ! Doesn't appear to be working.
	*argv = "nothing";
	// Ton of helpful shit here. Command line arguments.
	if (strcmp(argv[1], "-basic") == 0 || strcmp(argv[1], "-Basic") == 0)
	{
		SkipMode = 1;
		std::string Mode = "1";
		CheckInput = 1;
	}
	if (strcmp(argv[1], "-LowPerf") == 0 || strcmp(argv[1], "-lowperf") == 0)
	{
		SkipMode = 2;
		std::string Mode = "2";
		CheckInput = 2;
	}
	if (strcmp(argv[1], "-HighPerf") == 0 || strcmp(argv[1], "-highperf") == 0)
	{
		SkipMode = 3;
		std::string Mode = "3";
		CheckInput = 3;
	}
	if (strcmp(argv[1], "-Expert") == 0 || strcmp(argv[1], "-expert") == 0)
	{
		SkipMode = 4;
		std::string Mode = "4";
		CheckInput = 4;
	}
	if (strcmp(argv[1], "-IgnoreDir") == 0 || strcmp(argv[1], "-ignoredir") == 0)
	{
		KernelDirectorySpookiness = 99;
	}
	if (strcmp(argv[1], "-id") == 0 || strcmp(argv[1], "-ID") == 0)
	{
		KernelDirectorySpookiness = 99;
	}
	if (strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "-Help") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-H") == 0)
	{
		printf("Commands: \n");
		printf("-IgnoreDir / -ignoredir / -id / -ID: Disable directory checking. Useful when I can't detect if your directory contains a kernel.\n");
		printf("-help / -Help / -h / -H: Shows this help dialogue.\n");
		printf("-basic / -lowperf / -highperf / -expert: Sets the mode, and skips mode checking.");
		printf("Press enter to exit.");
		std::cin.ignore();
		return 0;
	}

	// Main annoucement
    printf("Sapphire's Kernel Installer!\n");
	printf("Version 1.0\n");

// Check if this is a kernel directory
	if (access("vmlinux-gdb.py", F_OK) != -1) {
		KernelDirectorySpookiness = KernelDirectorySpookiness + 1;
	}
	if (access("CREDITS", F_OK) != -1) {
		KernelDirectorySpookiness = KernelDirectorySpookiness + 1;
	}
	if (access("README", F_OK) != -1) {
		KernelDirectorySpookiness = KernelDirectorySpookiness + 1;
	}
	if (access(".version", F_OK) != -1) {
		KernelDirectorySpookiness = KernelDirectorySpookiness + 1;
	}
	if (KernelDirectorySpookiness > 2) {
		printf("This directory seems to be a kernel directory.\n");
	}
	else {
		printf("This doesn't seem to be a directory containing a kernel. Place this in a kernel directory.\n");
		printf("Press enter to exit.");
		std::cin.ignore();
		return 0;
	}

	// Select kernel mode
	if (SkipMode = 0) {
		std::string Mode;
		printf("Select mode:\n");
		printf("1. Basic\n");
		printf("2. Low performance\n");
		printf("3. High performance\n");
		printf("4. Expert\n");
		std::getline(std::cin, Mode);
		NumberOfThreads = sysconf(_SC_NPROCESSORS_ONLN);
		std::system("clear");
		// Workaround for mode selection failure
		// ! Does not appear to be working
		if (Mode == "4") {
			CheckInput = 4;
			if (Mode == "3") {
				CheckInput = 3;
				if (Mode == "2") {
					CheckInput = 2;
					if (Mode == "1") {
						CheckInput = 1;
					}
				}
			}
		}
	}

	if (CheckInput < 1) {
		system("clear");
		printf("Invalid selection. Only use 1, 2, 3, or 4.");
		printf("Press enter to exit.");
		std::cin.ignore();
		return 0;
	}
	if (CheckInput > 4) {
		system("clear");
		printf("Invalid selection. Only use 1, 2, 3, or 4.");
		printf("Press enter to exit.");
		std::cin.ignore();
		return 0;
	}



// Check if the main config file is there
	if (access(".config", F_OK) != -1) {
		printf("Config found.\n");
	}
	else {
		printf("Config not found. Generating.\n");
		system("cp /boot/config-`uname -r` .config");
		if (access(".config", F_OK) != -1) {
			printf("Config found.\n");
		}
		else {
			printf("Config file could not be pulled from your current kernel config. Please make it yourself by running 'make menuconfig'.\n");
			system("cp /boot/config-`uname -r` .config");
			printf("Press enter to exit.");
			std::cin.ignore();
			return 0;
		}
	}

	// get depends
	system("sudo apt-get install git fakeroot build-essential ncurses-dev xz-utils libssl-dev bc flex libelf-dev bison -y");

	// Decide which mode will be used
	if (CheckInput = 1) {
		system("clear");
		printf("Cleaning the output.");
		system("make clean");
		// Make this function better. Array? Foreach? 
		if (NumberOfThreads == 1 || NumberOfThreads ==  3 || NumberOfThreads ==  5 || NumberOfThreads ==  NumberOfThreads ==  7 || NumberOfThreads ==  9 || NumberOfThreads ==  11 || NumberOfThreads ==  13 || NumberOfThreads ==  15 || NumberOfThreads ==  17 || NumberOfThreads ==  19 || NumberOfThreads ==  21 || NumberOfThreads ==  23 || NumberOfThreads ==  25 || NumberOfThreads ==  27 || NumberOfThreads ==  29 || NumberOfThreads ==  31 || NumberOfThreads ==  33 || NumberOfThreads ==  35 || NumberOfThreads ==  37 || NumberOfThreads ==  39 || NumberOfThreads ==  41 || NumberOfThreads ==  43 || NumberOfThreads ==  45 || NumberOfThreads ==  47 || NumberOfThreads ==  49 || NumberOfThreads ==  51 || NumberOfThreads ==  53 || NumberOfThreads ==  55 || NumberOfThreads ==  57 || NumberOfThreads ==  59 || NumberOfThreads ==  61 || NumberOfThreads ==  63 || NumberOfThreads ==  65 || NumberOfThreads == 67 || NumberOfThreads ==  69) {
			NumberOfThreads = NumberOfThreads + 1;
		}
		NumberOfThreads = NumberOfThreads / 2;
		(BasicMakeModulesInstall += NumberOfThreads);
		system("clear");
		(BasicMakeInstall += NumberOfThreads);
		system("clear");
		printf("Making the modules for installation.");
		system(BasicMakeModulesInstall);
		printf("Making and installing the kernel.");
		system(BasicMakeInstall);
		printf("All done. Reboot and enjoy.");

	}


	if (CheckInput = 2) {
		system("clear");
		printf("Cleaning the output.");
		system("make clean");
		system("clear");
		printf("Making the modules for installation.");
		system(BasicMakeModulesInstall);
		printf("Making and installing the kernel.");
		system(BasicMakeInstall);
		printf("All done. Reboot and enjoy.");
	}


	if (CheckInput = 3) {
		system("clear");
		printf("Cleaning the output.");
		system("make clean");
		(BasicMakeModulesInstall += NumberOfThreads);
		system("clear");
		(BasicMakeInstall += NumberOfThreads);
		system("clear");
		printf("Making the modules for installation.");
		system(BasicMakeModulesInstall);
		printf("Making and installing the kernel.");
		system(BasicMakeInstall);
		printf("All done. Reboot and enjoy.");
	}

	// This section needs a lot of work. All kernel parameters must be exposed and usable.
	if (CheckInput = 4) {
		printf("Expert mode is disabled in this release.");
	// printf("Cleaning the output.");
	// system("make clean");
	// (BasicMakeModulesInstall += NumberOfThreads);
	// system("clear");
	// (BasicMakeInstall += NumberOfThreads);
	// system("clear");
	// printf("Making the modules for installation.");
	// system(BasicMakeModulesInstall);
	// printf("Making and installing the kernel.");
	// system(BasicMakeInstall);
	// printf("All done. Reboot and enjoy.");
	}
//End of file. If everything goes well, return 0.
	printf("Press enter to exit.");
	std::cin.ignore();
    return 0;
}
