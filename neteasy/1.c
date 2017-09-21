#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* getMem(void)
{
	char* p = "hello world";
	return p;
}
void test(void)
{
	char* str = getMem();
	printf("%s\n", str);
	printf(str);
}
int main(int argc, char const *argv[])
{
	test();
	printf("xixxixix\n");
	return 0;
}