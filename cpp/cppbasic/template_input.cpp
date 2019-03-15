#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{ 
	//提交代码之前，请将该行代码注释掉
	std::ifstream cin("testcase.txt");

	int n = 0;
	int temp = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		std::cout << i << ":"<< temp << std::endl;
	}
	
	return 0;
}