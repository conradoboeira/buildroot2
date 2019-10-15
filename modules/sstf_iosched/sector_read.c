/*
 * Simple disc I/O generator
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_LENGTH 512
#define DISK_SZ	1073741824

int main(){
	int ret, fd, pid, i;
	unsigned int pos;
	char buf[BUFFER_LENGTH];

	printf("Starting sector read example...\n");

	printf("Cleaning disk cache...\n");
	system("echo 3 > /proc/sys/vm/drop_caches");

	system("modprobe sstf-iosched");
	system("echo sstf > /sys/block/sdb/queue/scheduler");

	for(i = 0; i < 100; i++){
	    pid_t pid = fork();
	    if(pid == 0) break;
	}

	srand(getpid());
	//srand((unsigned)time(NULL));

	fd = open("/dev/sdb", O_RDWR);
	if (fd < 0){
		perror("Failed to open the device...");
		return errno;
	}

	strcpy(buf, "hello world!");

	for (i = 0; i < 10; i++){
	    pos = (rand() % (DISK_SZ >> 9));
	    /* Set position */
	    lseek(fd, pos * 512, SEEK_SET);
	    /* Peform read. */
	    read(fd, buf, 100);
	}

	close(fd);

	return 0;
}
