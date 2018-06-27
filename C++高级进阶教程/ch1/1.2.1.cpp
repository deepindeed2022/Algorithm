#include <iostream>
using namespace std;
void showvalue(const int& j)
{
	std::cout << j << std::endl;
}
int main(int argc, char const *argv[])
{
	const int j = 5;
	int* ptr;
	void*p = (void*)&j;
	ptr = (int*)p;
	(*ptr)++;
	std::cout << j << std::endl;
	std::cout << *ptr << std::endl;
	const int &r = 5;

	return 0;
}
