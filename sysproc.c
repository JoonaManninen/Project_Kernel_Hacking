#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int callnum[25]; //contains counters for all system calls


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// Function to get the count of a specific system call
int
sys_getreadcount(void)
{
  // call is the system call we want to follow
	int call;	
	if(argint(0, &call) < 0) {
		return -1;
		
	}
	//return count value with input index call-1
	return callnum[call-1];
}

// Return count value with input index calltofollow-1
int sys_countereset(void)
{

	int input;

  // Check if the input is valid
	if(argint(0, &input) < 0) {
		return -1;
		
	}

	// Reset all counters if input is 0
	if(input == 0) {
		 for(int i=0;i<25;i++){
			callnum[i] = 0;
		}
		return 1;
	}

	//reset one with index input-1
	callnum[input-1] = 0;

	return 0;
}