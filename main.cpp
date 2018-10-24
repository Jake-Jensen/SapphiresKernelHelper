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


int KernelDirectorySpookiness = 0;
int SkipCheck = 0;
char _Name[50];


void Check()
{
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
			system("clear");
			printf("Config file could not be pulled from your current kernel config. Please make it yourself by running 'make menuconfig'.\n");
			printf("Press enter to exit.");
			std::cin.ignore();
			exit(1);
		}
	}
}


void GetDepends()
{
	// get depends
	system("sudo apt-get install git fakeroot build-essential libncurses5-dev xz-utils libssl-dev bc flex libelf-dev bison -y");
}

void Basic()
{
	if (SkipCheck = 0) {
		Check();
	}
	else {

	}
	system("make clean");
	int ret = system("make clean");
	if (WEXITSTATUS(ret) == 0x10) {
		int ret = system("make -j 4");
		if (WEXITSTATUS(ret) == 0x10) {
			int ret = system("make modules -j 4");
			if (WEXITSTATUS(ret) == 0x10) {
				int ret = system("make modules install -j 4");
				if (WEXITSTATUS(ret) == 0x10) {
					int ret = system("make install -j 4");
					if (WEXITSTATUS(ret) == 0x10) {
					}
					else {
						printf("Failed to install the kernel.\n");
						printf("Press enter to exit.");
						std::cin.ignore();
						exit(1);
					}
				}
				else {
					printf("Failed to install modules.\n");
					printf("Press enter to exit.");
					std::cin.ignore();
					exit(1);
				}
			}
			else {
				printf("Failed to make modules.\n");
				printf("Press enter to exit.");
				std::cin.ignore();
				exit(1);
			}
		}
		else {
			printf("Failed to make.\n");
			printf("Press enter to exit.");
			std::cin.ignore();
			exit(1);
		}
	}
	else {
		printf("Failed to clean the output.\n");
		printf("Press enter to exit.");
		std::cin.ignore();
		exit(1);
	}

	printf("All done. Reboot and enjoy.\n");
	exit(0);
}

void LowPerf()
{

	if (SkipCheck = 0) {
		Check();
	}
	else {

	}
	system("make clean");
	int ret = system("make clean");
	if (WEXITSTATUS(ret) == 0x10) {
		int ret = system("make -j 1");
		if (WEXITSTATUS(ret) == 0x10) {
			int ret = system("make modules -j 1");
			if (WEXITSTATUS(ret) == 0x10) {
				int ret = system("make modules install -j 1");
				if (WEXITSTATUS(ret) == 0x10) {
					int ret = system("make install -j 1");
					if (WEXITSTATUS(ret) == 0x10) {
					}
					else {
						printf("Failed to install the kernel.\n");
						printf("Press enter to exit.");
						std::cin.ignore();
						exit(1);
					}
				}
				else {
					printf("Failed to install modules.\n");
					printf("Press enter to exit.");
					std::cin.ignore();
					exit(1);
				}
			}
			else {
				printf("Failed to make modules.\n");
				printf("Press enter to exit.");
				std::cin.ignore();
				exit(1);
			}
		}
		else {
			printf("Failed to make.\n");
			printf("Press enter to exit.");
			std::cin.ignore();
			exit(1);
		}
	}
	else {
		printf("Failed to clean the output.\n");
		printf("Press enter to exit.");
		std::cin.ignore();
		exit(1);
	}

	printf("All done. Reboot and enjoy.\n");
	exit(0);

}

void HighPerf()
{

	if (SkipCheck = 0) {
		Check();
	}
	else {

	}
	system("make clean");
	int ret = system("make clean");
	if (WEXITSTATUS(ret) == 0x10) {
		int ret = system("make -j `getconf _NPROCESSORS_ONLN`");
		if (WEXITSTATUS(ret) == 0x10) {
			int ret = system("make modules -j `getconf _NPROCESSORS_ONLN`");
			if (WEXITSTATUS(ret) == 0x10) {
				int ret = system("make modules install -j `getconf _NPROCESSORS_ONLN`");
				if (WEXITSTATUS(ret) == 0x10) {
					int ret = system("make install -j `getconf _NPROCESSORS_ONLN`");
					if (WEXITSTATUS(ret) == 0x10) {
					}
					else {
						printf("Failed to install the kernel.\n");
						printf("Press enter to exit.");
						std::cin.ignore();
						exit(1);
					}
				}
				else {
					printf("Failed to install modules.\n");
					printf("Press enter to exit.");
					std::cin.ignore();
					exit(1);
				}
			}
			else {
				printf("Failed to make modules.\n");
				printf("Press enter to exit.");
				std::cin.ignore();
				exit(1);
			}
		}
		else {
			printf("Failed to make.\n");
			printf("Press enter to exit.");
			std::cin.ignore();
			exit(1);
		}
	}
	else {
		printf("Failed to clean the output.\n");
		printf("Press enter to exit.");
		std::cin.ignore();
		exit(1);
	}

	printf("All done. Reboot and enjoy.\n");
	exit(0);
}

void Expert()
{
	Check();
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
	exit(1);
}

// void DistName()
// {
// 	printf("Specify a name for this kernel.\n");
// 	printf("Name should be all lowercase and not contain symbols.\n");
// 	char _Name[50];
// 	fgets(_Name, sizeof _Name, stdin);
// 	_Name[strcspn(_Name, "\n")] = 0;
// 
// 
// }

void Distribution()
{
	Check();

	system("make clean");
	int ret = system("make clean");
	if (WEXITSTATUS(ret) == 0x10) {
		int ret = system("fakeroot make-kpkg --initrd --append-to-version=-custom kernel_image kernel_headers modules -j `getconf _NPROCESSORS_ONLN`");
		if (WEXITSTATUS(ret) == 0x10) {
			printf("All done. Reboot and enjoy\n");
			exit(0);
		}
		else {
			printf("Failed to compile kernel for distribution.\n");
			printf("Press enter to exit.");
			std::cin.ignore();
			exit(1);
		}
	}
	else {
		printf("Failed to clean the output.\n");
		printf("Press enter to exit.");
		std::cin.ignore();
		exit(1);
	}

	printf("All done. Reboot and enjoy.\n");
	exit(0);
}


int main()
{
	// Debug flags
	KernelDirectorySpookiness = 0;
	SkipCheck = 0;

	// Main annoucement
	printf("Sapphire's Kernel Installer!\n");
	printf("Version 1.1\n");

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
		printf("Press enter to exit.");
		std::cin.ignore();
		return 0;
	}

	// Select kernel mode
	printf("Select mode:\n");
	printf("1. Basic\n");
	printf("2. Low performance\n");
	printf("3. High performance\n");
	printf("4. Expert\n");
	printf("5. Distribution\n");
	char Mode[50];
	fgets(Mode, sizeof Mode, stdin);
	std::system("clear");
	if (strcmp(Mode, "5\n") == 0) {
		system("clear");
		printf("Gathering dependencies.\n");
		sleep(1);
		GetDepends();
		// Disabled in current release
		// DistName();
		printf("Starting build.\n");
		sleep(1);
		Distribution();
	}
	if (strcmp(Mode, "4\n") == 0) {
		system("clear");
		printf("Gathering dependencies.\n");
		sleep(1);
		GetDepends();
		printf("Starting build.\n");
		sleep(1);
		Expert();
	}
	if (strcmp(Mode, "3\n") == 0) {
		system("clear");
		printf("Gathering dependencies.\n");
		sleep(1);
		GetDepends();
		printf("Starting build.\n");
		sleep(1);
		HighPerf();
	}
	if (strcmp(Mode, "2\n") == 0) {
		system("clear");
		printf("Gathering dependencies.\n");
		sleep(1);
		GetDepends();
		printf("Starting build.\n");
		sleep(1);
		LowPerf();
	}
		
	if (strcmp(Mode, "1\n") == 0) {
		system("clear");
		printf("Gathering dependencies.\n");
		sleep(1);
		GetDepends();
		printf("Starting build.\n");
		sleep(1);
		Basic();
	}

	system("clear");
	printf("Invalid selection. Only use 1, 2, 3, 4, or 5.\n");
	printf("Press enter to exit.\n");
	std::cin.ignore();
	return 0;


	//End of file. If everything goes well, return 0.
	printf("Press enter to exit.");
	std::cin.ignore();
	return 0;
}
