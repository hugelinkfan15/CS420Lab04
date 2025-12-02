#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr,"Usage: %s <file>\n", argv[0]);
		return 1;
	}
	
	FILE *file = fopen(name, "w");
	char* buffer = malloc(1024000);
	for(int i=0;i<1024000;i++)
		{
			buffer[i] = rand() %128 ;
		}
	fwrite(buffer,1,1024000,file);
	fclose(file);
	
	free(buffer);
}