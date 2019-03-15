#include <iostream>
#include <string>
using namespace std;
void printHello()
{
	cout<<""<<endl;
	string name="曹文龙";
	const std::string greeting = "hello, "+name+"!";
	const string spaces(greeting.size(),' ');
	const string second="*"+spaces+"*";
	const string first(second.size(),'*');

	cout<<first<<endl;
	cout<<second<<endl;
	cout<<"* "<<greeting<<" *"<<endl;
	cout<<second<<endl;
	cout<<first<<endl;
}
int  main()
{
	
	printHello();
	cin.get();
	return 1;
}