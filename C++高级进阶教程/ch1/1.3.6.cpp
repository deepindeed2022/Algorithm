#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int i = 5;
	const int& ri = i;
	std::cout << ri << std::endl;
	int*p = &j;
	*p = 6;
	std::cout << ri << std::endl;
	return 0;
}
