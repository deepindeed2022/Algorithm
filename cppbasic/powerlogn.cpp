/**
 * O(logN)的时间复杂度
 * Note:
 * 需要记住的是，double类型和float类型是不能直接比较大小的，需要近似比较大小。
 */
#include <iostream>
#include <cassert>

double power(double base, int exponent);
bool eq(double a, double b)
{
	if(a-b <0.0000001 | a-b > -0.0000001 )
		return true;
	return false;
}
double power(double base, int exponent)
{
	if(eq(base, 0.0) && exponent >= 0)
		return 0.0;
	else if(eq(base, 0.0) && exponent < 0)
	{
		//std::cout<<"The base is zero, and the exponent shouldn't be nagetive interger!"<<std::endl;
		return -1;
	}
	else if(!eq(base, 0.0) && exponent < 0)
	{
		return 1.0/power(base,-exponent);
	}
	else
	{
		double result = 1.0;
		while(exponent > 0)
		{
			std::cout << exponent << std::endl;
			if(exponent & 0x01)
			{
				result *= base;
			}
			base *= base;
			exponent=exponent>>1;
		}
		return result;
	}

}
int main(int argc, char const *argv[])
{
	assert(power(0.0, -1) < 0);
	assert(eq(power(2.0, -1),0.5));
	assert(eq(power(2.0, 2),4));
	assert(eq(power(0.0, 3),0) );
	assert(eq(power(0.0, 0),0 ));
	return 0;
}