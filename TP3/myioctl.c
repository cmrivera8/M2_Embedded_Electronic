#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define IOCDL_SET_MSG 1

void ioctl_set_msg(int file_desc, char *message){
	int ret_val;
	ret_val=ioctl(file_desc, IOCDL_SET_MSG, message);
	printf("set_msg message: %s\n", message);
}


int main(int argc,char **argv){
	int file_desc, ret_val;
	char msg[30]="Message sent to ioctl\n";
	
	file_desc=open("/dev/ppp", O_RDWR);
	ioctl_set_msg(file_desc,msg);
	close(file_desc);
	
	return 0;
}
