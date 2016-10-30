#include <iostream>
#include <string.h>
using namespace std;
/***********************************************

 Define a func parameter
************************************************/
#define FUNC_PARAM char*, const int size, int start


typedef void(*PF_RET_VOID)(FUNC_PARAMB);

// typedef int(*PF_RET_INT)(void);
void haveIncludeStr_method1(char* s, const int size, int start)
{
	std::cout <<"The string:" << s << std::endl;
	std::cout << "The size:" << size << std::endl;
}
void test_all(PF_RET_VOID p)
{
	char a[] = "Hello";
	int size = strlen(a);
	(*p)(a, size, 0);


}
int main(int argc, char const *argv[])
{
	test_all(haveIncludeStr_method1);
	return 0;
}