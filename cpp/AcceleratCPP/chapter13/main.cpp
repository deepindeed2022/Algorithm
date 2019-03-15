#include <vector>
using std::vector;
#include <iostream> 
using std::cout;
using std::streamsize;
using std::cin;
using std::endl;
#include <algorithm>
using std::sort;
using std::max;
#include <stdexcept>
using std::domain_error;
#include <string>
using std::string;
#include <iomanip>
using std::setprecision;
#include "core.h"
bool compare(Core c1,Core c2)
{
	return c1.grade()<c2.grade();
}
bool compare_Core_ptrs(const Core* cp1,const Core* cp2)
{
	return compare(*cp1,*cp2);
}
std::vector<Core*> students;
int main()
{
	
	Core* record;
	char ch;
	string::size_type maxlen = 0;
	while(cin>>ch)
	{
		if(ch=='U')
			record = new Core;
		else 
			record = new Grad;
		record->read(cin);
		maxlen = max(maxlen,record->name().size());
		stduents.push_back(record);
	}
	//alphabetize the student records
	sort(students.begin(),students.end(),compare_Core_ptrs);
	for(vector<Core*>::size_type i=0;i!=students.size();i++)
	{
		cout<<students[i]->name()<<string(maxlen+1-students[i]->name().size(),' ');
		try{
			double final_grade = students[i]->grade();
			streamsize prec = cout.precision();
			cout<<setprecision(3)<<final_grade<<setprecision(prec)<<'\n';

		}catch(domain_error e)
		{
			cout<<e.what()<<endl;
		}
	}
	return 0;
}