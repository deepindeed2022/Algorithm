#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int const**p1; // 
	int* const*p2; //指向指针常量的指针
	int i = 5;
	int j = 6;
	const int*ptr1=&i; // 常指针
	int* const ptr2 =&j; // 指针常量
	// ptr2 = &i;

	p1 = &ptr1;
	p2 = &ptr2;
	std::cout << **p1 << std::endl;
	std::cout << **p2 << std::endl;
	return 0;
}