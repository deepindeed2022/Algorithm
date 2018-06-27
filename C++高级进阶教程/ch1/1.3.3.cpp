#include <iostream>
using namespace std;
class A
{
	int num;
public:
	A(){num = 5;}
	void disp();
	void disp() const;
	void set(int n) { num = n;}	
};

void A::disp() const {
	std::cout << num << std::endl;
}
void A::disp(){
	
	std::cout << "Another version of disp()" << std::endl;
}

int main(int argc, char const *argv[])
{
	A a1;
	a1.set(3);
	a1.disp();
	A const a2;
	a2.disp();
	// 强制类型转换
	((const A*)&a1)->disp();
	return 0;
}