#include <iostream>
using namespace std;
int mySqrt(int x)
{
	if(x <= 0) return 0;
	int left = 1;
	int mid;
	int right = x;
	while(left <= right)
	{
		mid = (right  + left)/2;
		if(x/mid > mid)
		{
			left = mid + 1;
		}else if(x/mid  < mid)
		{
			right = mid - 1;
		}else
		{
			return mid;
		}
		
	}
	if(right*right >x)
		return right - 1;
	return right;
}
void test_sqrt()
{
	std::cout << mySqrt(5) << std::endl;
	std::cout << mySqrt(6) << std::endl;
	std::cout << mySqrt(9) << std::endl;
	std::cout << mySqrt(15) << std::endl;

}
int main(int argc, char const *argv[])
{
	test_sqrt();
	return 0;
}