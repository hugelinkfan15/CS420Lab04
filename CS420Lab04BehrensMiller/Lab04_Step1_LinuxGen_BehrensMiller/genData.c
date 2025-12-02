#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	//May come back to this, want to have program check to see if
	//user typed in .txt extension, if not append it to end of filename
	/*int length = 0;
	while (argv[1][length] != '\0')
		length++;
	
	char *name = malloc(length + 5);
	sprintf(name, "%s.txt", argv[1]);*/
	
	FILE *file = fopen(name, "w");
	char* buffer = malloc(1024000);
	for(int i=0;i<1024000;i++)
		{
			buffer[i] = rand() %128 ;
		}
	fwrite(buffer,1,1024000,file);
	fclose(file);
	
	free(buffer);
	//free(name);
}