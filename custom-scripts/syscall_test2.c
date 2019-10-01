#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>

#define SYSCALL_PROCESSINFO	386

void usage(char* s){
	printf("Usage: %s <PID>\n", s);
	exit(0);
}



int main(int argc, char** argv){  

	long buf[256];
	long ret;


	printf("Invoking 'listProcessInfo' system call.\n");
	ret = syscall(SYSCALL_PROCESSINFO, buf, sizeof(buf)); 

	if(ret > 0) {
	/* Success, show the process info. */
		printf("%ld\n", buf[0]);
	}

	else {
		printf("System call 'listProcessInfo' did not execute as expected error %d\n", ret);
	}

	return 0;

}
