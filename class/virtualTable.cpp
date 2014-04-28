#include <iostream>
using namespace std;
class A
{int c;};
class B
{
public:
	int i;
	virtual int add(int i);
	//int g;
};
class C
{
	virtual int add(int i);
};

class D:public B
{
public:
	int k;
};
int main(int argc, char const *argv[])
{
	//B b;
	//b.i=10;
	cout<<"A "<<sizeof(A)<<endl;
	cout<<"B "<<sizeof(B)<<endl;
	cout<<"C "<<sizeof(C)<<endl;
	cout<<"D "<<sizeof(D)<<endl;
	cout<<sizeof(int)<<endl;
	
	return 0;
} 
