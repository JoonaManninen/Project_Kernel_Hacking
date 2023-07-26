#include "types.h"
#include "user.h"
#include "stat.h"


int main(int argc, char *argv[]){
	// Checking that there is enough arguments
	if(argc < 2){
    		printf(1, "Not enough arguments.\n");
    		exit();
	}

	int arg = atoi(argv[1]);

    const char *systemcalls[] = {
		"fork",
		"exit",
		"wait",
		"pipe",
		"read",
		"kill",
		"exec",
		"fstat",
		"chdir",
		"dup",
		"getpid",
		"sbrk",
		"sleep",
		"uptime",
		"open",
		"write",
		"mknod",
		"unlink",
		"link",
		"mkdir",
		"close",
		"getreadcount",
		"countereset"
	};
	printf(1, "%s system call has been executed %d times.\n", systemcalls[arg-1], getreadcount(arg));
	exit();
}