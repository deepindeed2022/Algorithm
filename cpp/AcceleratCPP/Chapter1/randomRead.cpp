#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LINE_LEN 4096
int main()
{
	srand(time(NULL));
	const char *filename = "english.word";
	FILE * file = fopen(filename, "r");
	char line_buffer[MAX_LINE_LEN];
	char selection[MAX_LINE_LEN];
	int i = 1;
	while(fgets(line_buffer, MAX_LINE_LEN, file))
	{
		if(rand()%i == 0) //
			strcpy(selection, line_buffer);
		++i;
	}
	puts(selection);
	fclose(file);
	return 0;
}