#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

//argv[1] should be source file, argv[2] should be target file
int main(int argc, char *argv[])
{
	if(argc !=3)
	{
		fprintf(stderr, "Usage: %s <sourcefile> <targetfile>\n", argv[0]);
		return 1;
	}
	size_t bufSize = 4096;
	char* buffer = malloc(bufSize);
	int original = open(argv[1], O_RDONLY, 0644);
	int copy = open(argv[2], O_WRONLY | O_CREAT , 0644);
	
	unsigned int bytesRead;
	
	while(1)
	{
		bytesRead = read(original,buffer, bufSize);
		if(bytesRead == 0)
			break;
		write(copy, buffer, bytesRead);
	}
	
	close(copy);
	close(original);
	free(buffer);
	return 0;
}
