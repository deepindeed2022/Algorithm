#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4};
	int* p = &a[4];
	for (int i = 3; i >= 0; --i)
	{
		std::cout << *(--p) << std::endl;
	}
	return 0;
}
