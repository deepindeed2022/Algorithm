#include <iostream>
#include <assert.h>
using namespace std;
#include <stdio.h>
#define stub  fprintf(stderr, "error param in %s:%s:%d\n",  __FUNCTION__, __FILE__, __LINE__);
void test()
{
	assert(5 == 5);
}
int main(int argc, char const *argv[])
{
	stub
	test();
	stub
	return 0;
}