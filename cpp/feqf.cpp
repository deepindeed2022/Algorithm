#include <cstdio>
void run()
{
	printf("Hello\n");
}
int f()
{
	return new char - "";
}
int main(int argc, char const *argv[])
{
	printf("%d\n",f());
	printf("%d\n",f());
	if(f() != f())
		run();
	return 0;
}