#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

//argv[1] should be the file to be deleted
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <target_path>\n", argv[0]);
		return 1;
	}
	struct stat metaData;
	lstat(argv[1],&metaData);
	
	
	if (S_ISDIR(metaData.st_mode))
	{
		rmdir(argv[1]);
	}
	else if (S_ISREG(metaData.st_mode))
	{
		unlink(argv[1]);
	}
}