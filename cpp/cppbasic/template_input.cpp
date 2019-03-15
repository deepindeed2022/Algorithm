#include <iostream>
#include <fstream>
using namespace std;
int main()
{ 
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