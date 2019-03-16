#include <iostream>
#include <memory>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <climits>
using namespace std;
void test_char2int()
{
	uint8_t a[] = {1, 1, 0, 0, 2, 1, 0, 0, 3, 1, 0, 0, 4, 1, 0, 0};
	uint32_t* iptr = (uint32_t*) malloc(sizeof(a));
	memcpy(iptr, a, sizeof(a));
	for(int i = 0; i < sizeof(a)/sizeof(uint32_t); ++i)
	{
		std::cout << iptr[i]<< " ";
	}
	std::cout << endl;
}
//float还是double在存储方式上都是遵从IEEE的规范的，
//float遵从的是IEEE R32.24 ,而double 遵从的是R64.53
// float = |one bit for sign| 8bit for exponent| 23bit for mantissa
// double = |1| 11 |52|
void test_char2float()
{
	uint8_t a[] = {	0x01, 0x00, 0x00, 0x00, 
					0x01, 0x00, 0x00, 0x80, 
					0x00, 0x00, 0x80, 0x40,
					0x00, 0x00, 0x80, 0x41,
					0x80, 0x00, 0x00, 0x00, 
				};
	float* fptr = (float*) malloc(sizeof(a));
	memcpy(fptr, a, sizeof(a));
	for(int i = 0; i < sizeof(a)/sizeof(float); ++i)
	{
		std::cout << fptr[i]<< " ";
	}
	std::cout << endl;
	assert(fptr[0] + fptr[1] == 0.0);
	assert(fptr[0]*128 - fptr[2] < 1e-6);
}
void test_memset()
{
	uint8_t a[128] = {};
	memset(a, 0, 128);
	for(int i = 0; i < 128; ++i)
		a[i] = i;
	for(int i = 0; i < 128; ++i)
		std::cout << i << " " << a[i] << std::endl;
	std::cout << std::endl;
}
void test_sizeof()
{
	assert(sizeof(uint8_t) == 1);
	assert(sizeof(int8_t) == 1);
	assert(sizeof(uint16_t) == 2);
	assert(sizeof(int16_t) == 2);
	assert(sizeof(int) == 4);
	assert(sizeof(long) == 4);
	assert(sizeof(long long) == 8);
	assert(sizeof(float) == 4);
	assert(sizeof(double) == 8);

	assert(INT_MAX == 2147483647);
	std::cout << MB_LEN_MAX << std::endl;
	std::cout << UCHAR_MAX << std::endl;
	std::cout << USHRT_MAX << std::endl;
	std::cout << UINT_MAX << std::endl;
	std::cout << LONG_MAX << std::endl;
	std::cout << LLONG_MAX << std::endl;

}

std::string LOG_hello()
{
	return "## hello";
}
std::string LOG_bye()
{
	return "## bye";
}
// #，#@，##
#define INFO(value)	\
	std::cout <<__DATE__ << " " << __TIME__ <<" ";		\
	std::cout <<__FILE__ <<":" << __LINE__<< ":"		\
	<< LOG_##value() << std::endl;

#define LOG(value)	\
	std::cout << #value << std::endl;

void test_macro()
{
	INFO(hello);
	INFO(bye);
	LOG(log_hello);
	LOG(log_bye);
}
int main(int argc, char const *argv[])
{
	//test_char2int();
	//test_char2float();
	
	test_macro();

	return 0;
}
