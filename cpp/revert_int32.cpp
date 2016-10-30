#include <iostream>
#include <vector>
#include <cassert>

int revert_int(int _num)
{
	// integer  number bins length <= 32
	std::vector<bool> bin2(32, false);
	int counter = 0;
	int num =_num;
	while(num)
	{
		//std::cout<< " NUM:" << () << std::endl;
		bin2[counter++] = (num & 0x01== 0x01) ;
		num >>= 1;
	}
	/*
	std::cout<<"THE "<< _num<< " COUNTER : " << counter << std::endl;
	for (int i = 0; i < counter; ++i)
	{
		std::cout << bin2[i];
	}
	std::cout <<std::endl;
	*/
	int result = bin2[0];
	for(int i = 1; i < counter; ++i)
	{
		result <<= 1;
		result |= bin2[i] ? 0x01 : 0x00;
		//std::cout << i << " : "<< bin2[i]<< " : " << result << std::endl;
 	}
 	return result;
}

int main(int argc, char const *argv[])
{
	assert(revert_int(9) == 9);
	assert(revert_int(8) == 1);
	assert(revert_int(6) == 3);
	return 0;
}