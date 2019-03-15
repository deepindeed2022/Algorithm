/**
 * 不用if和循环实现求和1+2+3+4+...+n
 * 分析：
 *		不使用循环结构可以采用递归调用的方式，
 *		不使用判断可以采用shell中常用的（条件）&&（命令）的方式
 **/
#include <iostream>
#include <string>
#include <assert.h>

int fc_recursive(int n)
{
	int num = 0;

	(n > 0) && (num = n + fc_recursive(n-1));
	return num;
}

int main(int argc, char const *argv[])
{
	int n = 100;
	int totle = 0;
	int i = n;
	while(i > 0) totle += (i--);
	assert(fc_recursive(n) == totle);
	//std::cout << totle << std::endl;
	//std::cout <<fc_recursive(100) <<std::endl;
	return 0;
}