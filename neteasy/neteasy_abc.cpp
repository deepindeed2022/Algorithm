#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a_b;
	int b_c;
	int aplusb;
	int bplusc;
	std::cin >> a_b >>b_c>> aplusb >> bplusc;
	if(a_b + b_c != aplusb - bplusc)
	{
		std::cout <<"No" << std::endl;
		return 0;
	}
	int a,b,c,d;
	if((a_b + aplusb)%2 == 0)
	{
		a = (a_b + aplusb)/2;
	}
	else
	{
		std::cout <<"No" << std::endl;
		return 0;
	}

	if((b_c + bplusc)%2 == 0)
	{
		b = (b_c + bplusc)/2;
	}
	else
	{
		std::cout <<"No" << std::endl;
		return 0;
	}

	c = bplusc - b;
	if(b_c + c != b)
		std::cout <<"No" << std::endl;
	std::cout << a　<<" "<< b<<" " << c << std::endl;
	return 0;
}
