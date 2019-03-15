#include "core.h"
std::string Core::name() const 
{
	return n;
}
double Core::grade()const
{
	return ::grade(midterm,final,homework);
}
std::istream& Core::read(std::istream& in)
{
	in>>n>>midterm>>final;
	return in;
}
Core::Core():midterm(0),final(0)
{
	
}
Core::Core(std::istream& in)
{
	read(in);
}
~Core()
{
	std::cout<<"Core destroy;\n";
}
Grad::Grad();
Grad::Grad(std::istream&);
virtual double Grad::grade()const;
virtual std::istream& Grad::read(std::istream&);
Grad::~Grad();