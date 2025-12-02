#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

//argv[1] should be source file, argv[2] should be target file
int main(int argc, char *argv[])
{
	char* buffer = malloc(4096);
	int original = open(argv[1], O_RDONLY, 0644);
	int copy = open(argv[2], O_WRONLY | O_CREAT , 0644);
}