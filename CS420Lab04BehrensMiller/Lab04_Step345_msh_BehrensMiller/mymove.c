#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
	if (argc !=3)
	{
		fprintf(stderr,"Usage: %s <oldfilename> <newfilename>\n",argv[0]);
		return 1;
	}
	
	if(access(argv[1],F_OK) != 0)
	{
		fprintf(stderr,"File \"%s\" does not exist.\n", argv[1]);
		return 1;
	}
	link(argv[1],argv[2]);
	unlink(argv[1]);
	
	return 0;
}