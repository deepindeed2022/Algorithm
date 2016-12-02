#include <iostream>
using namespace std;
#include <vector>

int main(int argc, char const *argv[])
{
	std::cout << size_t(-1) << std::endl;
	std::cout << size_t(-1) / sizeof(int);
	ptrdiff_t t;
	int * a = new int();
	int * b = new int();
	t = b - a;
	t = 100;
	std::cout << t << std::endl;
	std::cout << sizeof(t) <<std::endl;
	std::cout << "Hello" <<endl;
	std::vector<int, std::allocator> vec(3, 0);

	return 0;
}