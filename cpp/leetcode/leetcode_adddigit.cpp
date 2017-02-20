// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
// For example:
// Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
// Follow up:
// Could you do it without any loop/recursion in O(1) runtime?
//
// https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
// 
#include <iostream>
#include <cassert>
#include <climits>
using namespace std;
int solution(int num)
{
	return 1 + (num-1) % 9;
}
void test_solution()
{
	assert(1 == solution(100));
	assert(3 == solution(102));
	assert(1 == solution(181));

}
int solution2(int num)
{
	if(num < 10) return num;
    return solution2(num / 10) + num % 10;
}
void test_solution2()
{
	assert(1 == solution2(100));
	assert(3 == solution2(102));
	assert(1 == solution2(181));

}
int main(int argc, char const *argv[])
{
	test_solution();
	test_solution2();
	return 0;
}