#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[])
{

	// Checking that there is enough arguments
	if (argc < 2)
	{
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
		"countereset"};

	// Resetting specific system call counter
	if (countereset(arg) == 1)
	{
		printf(1, "All system call counters reset\n");
		exit();
	}
	else if (countereset(arg) == 0)
	{ // Resetting all system call counters
		printf(1, "System call %s counter reset\n", systemcalls[arg - 1]);
		exit();
	}
}