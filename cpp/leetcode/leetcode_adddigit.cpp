#include <iostream>
using namespace std;
#include <cassert>
#include <climits>
int solution1(int num)
{
	if(num < 10) return num;
    return solution1(num / 10) + num % 10;
}
int solution(int num)
{
	return 1 + (num-1) % 9;
}
void test_solution()
{
	assert(1 == solution(100));
	assert(3 == solution(102));
	assert(10 == solution(181));

}
int main(int argc, char const *argv[])
{
	test_solution();
	std::cout << INT_MAX ;
	return 0;
}