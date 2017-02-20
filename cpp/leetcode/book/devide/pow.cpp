#include <iostream>
#include <assert.h>
#include <climits>
using namespace std;
double _pow(double x, int n);
double pow(double x, int n)
{
  	if( n == INT_MIN) return 1.0/(pow(x, -(n+1))*x); // handle the boundle of INT_MIN
	if(n < 0) return 1.0/pow(x, -n);
	else 
	{
		return _pow(x, n);
	}
}
double _pow(double x, int n)
{
	if(n == 0)
		return 1;

	double v = _pow(x, n/2);
	if(n % 2 == 0)
	{
		return v*v;
	}else
	{
		return v*v*x;
	}
}
void test_pow()
{
	double x = 5.6;
	assert(pow(x, 0)-1 < 1e-6);
	assert(pow(5.5, 1) - 5.5 < 1e-6);
	assert(pow(5.0, -1) - 0.2 < 1e-6);

}
int main(int argc, char const *argv[])
{
	test_pow();
	return 0;
}