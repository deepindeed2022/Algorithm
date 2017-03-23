// Given a positive integer, output its complement number. The complement strategy 
// is to flip the bits of its binary representation.
// Note:
// The given integer is guaranteed to fit within the range of a 32-bit signed integer.
// You could assume no leading zero bit in the integer’s binary representation.
// Example 1:
// 		Input: 5
// 		Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its 
// complement is 010. So you need to output 2.
//
// Example 2:
// 		Input: 1
// 		Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its 
// complement is 0. So you need to output 0.
//
#include <bitset>
#include <iostream>
#include <cassert>
using namespace std;

int findComplement(int num) {
    std::bitset<32> bitnum(num);
    int i = 31;
    bitnum.flip();
    while(i >= 0 && bitnum[i] == 1)
    {
    	bitnum.reset(i--);
    }
    return bitnum.to_ulong();   	
}
int findComplement_1(int num)
{
	unsigned mask = ~0;
	while(num & mask) mask <<= 1;
	return num ^ ~mask;
}

int main(int argc, char const *argv[])
{
	assert(findComplement_1(1) == 0);
	assert(findComplement_1(5) == 2);

	assert(findComplement(1) == 0);
	assert(findComplement(5) == 2);

	assert(findComplement_2(1) == 0);
	assert(findComplement_2(5) == 2);

	return 0;
}