#include <iostream>
#include <string>
#include <assert.h>

int fc_recursive(int n)
{
	int num = 0;
	(n > 0)&& (num = n + fc_recursive(n-1));
	return num;
}

int main(int argc, char const *argv[])
{
	int n = 100;
	int totle = 0;
	while(n > 0)
		totle += (n--);
	std::cout << totle << std::endl;
	std::cout <<fc_recursive(100) <<std::endl;
	return 0;
}