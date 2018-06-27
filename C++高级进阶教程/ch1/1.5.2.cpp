#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
	string Name;
	mutable int times_of_getname;
public:
	Student(char* name)
	{
		Name = name;
		times_of_getname = 0;
	}
	string get_name() const {
		times_of_getname++;
		return Name;
	}
	void printTimes() const {
		std::cout << times_of_getname << std::endl;
	}
};

int main(int argc, char const *argv[])
{
	const Student s("张三");
	std::cout <<s.get_name() << std::endl;
	std::cout <<s.get_name() << std::endl;
	s.printTimes();
	return 0;
}