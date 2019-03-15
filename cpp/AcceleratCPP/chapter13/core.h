#include <string>
#include <vector>
#include <iostream>
#ifndef CORE_H
#define CORE_H
class Core
{
public:
	Core();
	Core(std::istream&);
	std::string name()const;
	virtual std::istream& read(std::istream&);
	virtual double grade()const;
	virtual ~Core();
protected:
	std::istream& read_common(std::istream&);
	double midterm,final;
	std::vector<double> homework;
private:
	std::string n;
};
#endif
#ifndef GRAD_H
#define GRAD_H
class Grad: public Core
{
	public:
		Grad();
		Grad(std::istream&);
		virtual double grade()const;
		virtual std::istream& read(std::istream&);
		~Grad();
	private:
		double thesis;
};
#endif