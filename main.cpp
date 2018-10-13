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
#include <memory>
#include <stdexcept>
#include <array>
#include <condition_variable>

constexpr auto BUFSIZE = 128;

int KernelDirectorySpookiness = 0;
int NumberOfThreads = 0;
int CheckInput = -99;
int SkipMode = 0;
// const char *Mode = "Nothing";
const char *CMLArguments = NULL;
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
char *SystemCommand = NULL;


void GetDepends()
{
	// get depends
	system("sudo apt-get install git fakeroot build-essential libncurses5-dev xz-utils libssl-dev bc flex libelf-dev bison -y");
}

void Basic()
{
	system("make clean");
	system("make -j 4");
	system("make modules -j 4");
	system("make modules install -j 4");
	printf("Making and installing the kernel.\n");
	system("make install -j 4");
	printf("All done. Reboot and enjoy.\n");
}

void LowPerf()
{
	printf("Cleaning the output.");
	system("make clean");
	system("make -j 1");
	system("make modules -j 1");
	system("make modules install -j 1");
	printf("Making and installing the kernel.\n");
	system("make install -j 1");
	printf("All done. Reboot and enjoy.\n");
}

void HighPerf()
{
	printf("Cleaning the output.\n");
	system("make clean");
	system("make -j `getconf _NPROCESSORS_ONLN`");
	system("make modules -j `getconf _NPROCESSORS_ONLN`");
	system("make modules install -j `getconf _NPROCESSORS_ONLN`");
	printf("Making and installing the kernel.\n");
	system("make install -j `getconf _NPROCESSORS_ONLN`");
	printf("All done. Reboot and enjoy.\n");
}

void Expert()
{
	system("clear");
	printf("Expert mode is disabled in this release.\n");
	sleep(3);
	// printf("Cleaning the output.\n");
	// system("make clean");
	// system("make modules -j _NPROCESSORS_ONLN");
	// system("clear");
	// (BasicMakeInstall += NumberOfThreads);
	// system("clear");
	// printf("Making the modules for installation.");
	// system(BasicMakeModulesInstall);
	// printf("Making and installing the kernel.");
	// system(BasicMakeInstall);
	// printf("All done. Reboot and enjoy.");
	// printf("Expert was called.");
}


int main()
{
	// Debug flags
	// KernelDirectorySpookiness = 99;

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
	if (KernelDirectorySpookiness >= 2) {
		printf("This directory seems to be a kernel directory.\n");
	}
	else {
		printf("This doesn't seem to be a directory containing a kernel. Place this in a kernel directory.\n");
		printf("%d", KernelDirectorySpookiness);
		printf("Press enter to exit.");
		std::cin.ignore();
		return 0;
	}

	// Select kernel mode
	printf("Select mode:\n");
	printf("1. UNUSED LOW PERF\n");
	printf("2. Low performance\n");
	printf("3. High performance\n");
	printf("4. Expert\n");
	char Mode[50];
	fgets(Mode, sizeof Mode, stdin);
	NumberOfThreads = sysconf(_SC_NPROCESSORS_ONLN);
	std::system("clear");
	if (strcmp(Mode, "4\n") == 0) {
		system("clear");
		printf("Gathering dependencies.\n");
		sleep(1);
		GetDepends();
		printf("Starting build.\n");
		sleep(1);
		// Check if the main config file is there
		if (access(".config", F_OK) != -1) {
			printf("Config found.\n");
			Expert();
		}
		else {
			printf("Config not found. Generating.\n");
			system("cp /boot/config-`uname -r` .config");
			if (access(".config", F_OK) != -1) {
				printf("Config found.\n");
			}
			else {
				system("clear");
				printf("Config file could not be pulled from your current kernel config. Please make it yourself by running 'make menuconfig'.\n");
				printf("Press enter to exit.");
				std::cin.ignore();
				return 0;
			}
		}
	}
	else {
		if (strcmp(Mode, "3\n") == 0) {
			system("clear");
			printf("Gathering dependencies.\n");
			sleep(1);
			GetDepends();
			printf("Starting build.\n");
			sleep(1);
			// Check if the main config file is there
			if (access(".config", F_OK) != -1) {
				printf("Config found.\n");
				HighPerf();
			}
			else {
				printf("Config not found. Generating.\n");
				system("cp /boot/config-`uname -r` .config");
				if (access(".config", F_OK) != -1) {
					printf("Config found.\n");
				}
				else {
					system("clear");
					printf("Config file could not be pulled from your current kernel config. Please make it yourself by running 'make menuconfig'.\n");
					printf("Press enter to exit.");
					std::cin.ignore();
					return 0;
				}
			}
		}
		else {
			if (strcmp(Mode, "2\n") == 0) {
				system("clear");
				printf("Gathering dependencies.\n");
				sleep(1);
				GetDepends();
				printf("Starting build.\n");
				sleep(1);
				// Check if the main config file is there
				if (access(".config", F_OK) != -1) {
					printf("Config found.\n");
					LowPerf();
				}
				else {
					printf("Config not found. Generating.\n");
					system("cp /boot/config-`uname -r` .config");
					if (access(".config", F_OK) != -1) {
						printf("Config found.\n");
					}
					else {
						system("clear");
						printf("Config file could not be pulled from your current kernel config. Please make it yourself by running 'make menuconfig'.\n");
						printf("Press enter to exit.");
						std::cin.ignore();
						return 0;
					}
				}
			}
			else {
				if (strcmp(Mode, "1\n") == 0) {
					system("clear");
					printf("Gathering dependencies.\n");
					sleep(1);
					GetDepends();
					printf("Starting build.\n");
					sleep(1);
					// Check if the main config file is there
					if (access(".config", F_OK) != -1) {
						printf("Config found.\n");
						Basic();
					}
					else {
						printf("Config not found. Generating.\n");
						system("cp /boot/config-`uname -r` .config");
						if (access(".config", F_OK) != -1) {
							printf("Config found.\n");
						}
						else {
							system("clear");
							printf("Config file could not be pulled from your current kernel config. Please make it yourself by running 'make menuconfig'.\n");
							printf("Press enter to exit.");
							std::cin.ignore();
							return 0;
						}
					}
				}
				else {
					system("clear");
					printf("Invalid selection. Only use 1, 2, 3, or 4.\n");
					printf("Press enter to exit.\n");
					std::cin.ignore();
					return 0;
				}
			}
		}
	}


	//End of file. If everything goes well, return 0.
	printf("Press enter to exit.");
	std::cin.ignore();
	return 0;
}


