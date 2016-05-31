/*function:gourp the student who choose the HPC course
version:2016.3.8*/
/* description:
#1  read the file and store it in array S[]
#2  scatter accordding to the unit
#3 group
#4 print
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
struct student{
	int no;//1_column
	char id[20];
	char name[20];
	char major[40];
	char unit[50];
	char grade[1];
	char is_DegreeCourse[1];//0:no;1:yes
};

struct student STU[40];

/**
 * splite a string into a string array
 * \return the number of splite
 * \param spl: the splite characters
 * \param str: the input string
 **/
int split(char dst[][80], char str[], const char* spl)
{
	int n = 0;
	char* result = NULL;
	result = strtok(str, spl);
	while(result != NULL)
	{
		strcpy(dst[n++], result);
		result = strtok(NULL, spl);
	}
	return n;
}

/********** #1 read the file*********/
int readFile(const char* filename)
{
	FILE *fp;
	fp = fopen(filename,"rb");
	char dst[7][80] = {""};
	char* str = NULL;
	int i = 0;
	for(i = 0; i < 40 ;i++)
	{
		fscanf(fp,"%[^\n]",str);
		assert(7 == split(dst, str, ","));
		STU[i].no = (int)(dst[0]);
		strcpy(STU[i].id, dst[1]);
		strcpy(STU[i].name, dst[2]);
		strcpy(STU[i].major, dst[3]);
	}
	fclose(fp);
	return 0;
}

int main(int argc, char* input[])
{
	char dst[7][80] = {"","","","","","",""};
	char str[] = "39,2015E8016061044,张巧丽,计算机技术,计算机网络信息中心,,√";
	assert(6 == split(dst, str, ","));
	int i = 0;
	for (i = 0; i < 7; ++i)
	{
		printf("%d:%s\n",i,dst[i]);
	}
	//readFile("students.txt");
	
	
	return 0;
}