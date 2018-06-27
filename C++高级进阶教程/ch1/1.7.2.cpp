#include <iostream>
using namespace std;
class Small{

};

class LessFunc{
	int num;
	void func1(){};
};

class MoreFunc{
	int num;
	void func1(){}
	int func2(){return 1;};
};

class NeedAlign{
	char c;
	double b;
	int i;
};

class Virtual{
	double num;
	int num2;
	virtual void func(){};
};

class test
{
   char m1;
   unsigned int m2;
   char m3;
   double m4;
   char m5;
};

int main(int argc, char const *argv[])
{
	
	std::cout << sizeof(Small) << std::endl;
	std::cout << sizeof(LessFunc) << std::endl;
	std::cout << sizeof(MoreFunc) << std::endl;
	std::cout << sizeof(NeedAlign) << std::endl;
	std::cout << sizeof(Virtual) << std::endl;
	std::cout << sizeof(test) << std::endl;

	return 0;
}
