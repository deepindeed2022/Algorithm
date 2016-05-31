#include <stdio.h>
#include <string.h>
#include <assert.h>

struct student{
//	int no;//1_column
	char no[3];
	char id[20];
	char name[40];
	char major[40];
	char unit[50];
	char grade[1];
	char is_DegreeCourse[1];//0:no;1:yes
};
struct student STU[41];

void print(student& stu)
{
	printf("%s,",stu.no);
	printf("%s,",stu.id);
	printf("%s,",stu.name);
	printf("%s,",stu.major);
	printf("%s,",stu.unit);

	printf("\n");
}
void print_all(const int studentnum = 40)
{
	int i = 0;
	for (i = 0; i < studentnum; ++i)
	{
		print(STU[i]);
	}
}
int readFile(const char* filename = "students.txt")
{
	int i;
	FILE *fp;
	char str[200];
	char *pch = NULL;
	char *temp = NULL;
	if(!(fp = fopen(filename,"rb")))
		printf("file is null or file open failed\n");

	for(i = 0;i < 40;i++)
	{
		fscanf(fp,"%s\n",str);
		pch = strtok (str,",");
		if(pch !=NULL)
		{
			strcpy(STU[i].no,pch);
			pch = strtok(NULL,",");
		}
		if(pch !=NULL)
		{
			strcpy(STU[i].id,pch);
			pch = strtok (NULL,",");
		}
		if(pch !=NULL)
		{
			strcpy(STU[i].name,pch);
			pch = strtok (NULL,",");
		}

		if(pch !=NULL)
		{
			strcpy(STU[i].major,pch);
			pch = strtok (NULL,",");
		}
		if(pch !=NULL)
		{
			strcpy(STU[i].unit,pch);
			pch = strtok (NULL,",");
		}
	
		if(pch !=NULL)
		{
			strcpy(STU[i].grade,pch);
			pch = strtok (str,",");
		}
		
		if(pch !=NULL){
			strcpy(STU[i].is_DegreeCourse,pch);
		}
	}
	fclose(fp);
	return 0;
}

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

int test_spilt()
{
	char dst[7][80] = {"","","","","","",""};
	char str[] = "39,2015E8016061044,张巧丽,计算机技术,计算机网络信息中心,,√";
	assert(6 == split(dst, str, ","));
	char str2[] = "39,2015E8016061044,张巧丽,计算机技术,计算机网络信息中心,";
	assert(5 == split(dst, str2, ","));
	return 1;
}

int main(int argc, char* input[])
{
	//readFile();
	//print_all(); 
	test_spilt();
	return 0;
}



