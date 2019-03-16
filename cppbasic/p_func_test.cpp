#include <iostream>
#include <string.h>
using namespace std;

typedef void(*PF_RET_VOID)(char*, const int size, int start);

// typedef int(*PF_RET_INT)(void);

void haveIncludeStr(char* s, const int size, int start)
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
	test_all(haveIncludeStr);
	return 0;
}