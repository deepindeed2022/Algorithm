/**********************************************************************************************
 @description:
	Determine whether an integer is a palindrome. Do this without extra space.
 - Some hints:
	-Could negative integers be palindromes? (ie, -1)
	-If you are thinking of converting the integer to string, note the restriction of using 
	extra space.
	-You could also try reversing an integer. However, if you have solved the problem 
	 ”Reverse Integer”,
	-you know that the reversed integer might overflow. How would you handle such case?
	There is a more generic way of solving this problem
/**********************************************************************************************/
#include <iostream>
#include <cassert>
// // 错误方法
// bool is_palindrome(int x)
// {
// 	if(x < 0) return false;
// 	int d = 1;
// 	int l = 10;

// 	while(x/d > 10) d*= 10; // BUG: when x == 10, the will skip it.
	
// 	while(d > l)
// 	{
// 		if(x/d != x%l) return false;
// 		d %= 10; 	// FIXME: there should will be ignore almost test cases 
//					// such as 101010101
// 		l *= 10;
// 	}
// 	return true;
// }
bool is_palindrome(int x)
{
	if(x < 0) return false;
	int d = 1;
	
	while(x/d >= 10) d*= 10;
	//std::cout << d << std::endl;	
	while(x > 0)
	{
		if(x/d != x%10) return false;
		x = x%d / 10;
		d /= 100;
	}
	return true;
}
void test_is_palindrome()
{
	int a = -1;
	int b = 101;
	int c = 123454321;

	assert(!is_palindrome(a));
	assert(is_palindrome(b));
	assert(is_palindrome(c));
	assert(is_palindrome(0));
	assert(is_palindrome(1010101));
}
int main(int argc, char const *argv[])
{
	test_is_palindrome();
	return 0;
}