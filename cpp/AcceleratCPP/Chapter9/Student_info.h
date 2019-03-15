#ifndef STUDENT_INFO
#define STUDENT_INFO
class Student_info
{
public:
	
	std::istream& read(std::istream);
	double grade() const;
	bool valid()const{return !homework.empty();}
	std::string getName(){return name;}
private:
	std::string name;
	std::vector<double> homework;
	double midterm,final;
};
#endif