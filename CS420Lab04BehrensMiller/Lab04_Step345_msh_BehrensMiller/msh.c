#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <targetcommand>\n", argv[0]);
		return 1;
	}
	pid_t pid;
	
	if(strcmp(argv[1],"mycopy") == 0)
	{
		pid = fork();
		if(pid ==0)
		{
			execl("./mycopy",argv[1],argv[2],argv[3],0);
		}
		wait((int*)0);
	}
	else if(strcmp(argv[1],"myremove") == 0)
	{
		pid = fork();
		if(pid == 0)
		{
			execl("./myremove",argv[1],argv[2],0);
		}
		wait((int*)0);
	}
	else if(strcmp(argv[1],"mymove") == 0)
	{
		pid = fork();
		if(pid == 0)
		{
			execl("./mymove",argv[1],argv[2],argv[3],0);
		}
		wait((int*)0);
	}
	else
	{
		fprintf(stderr,"Valid command not passed!\nValid commands are:\tmycopy\tmyremove\tmymove\n");
		return 1;
	}
	return 0;
}