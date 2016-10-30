#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

#define FUNC_PARAM char*, const int size, int start
typedef void(*PF_RET_VOID)(FUNC_PARAM);

int main(int argc, char const *argv[])
{
	if(argc < 2)
		std::cout << "Please input a filename"<<std::endl;
	else{		
		string s(argv[1]);
		std::fstream fs;
		string filename = s;
		filename.append(".cpp");
	  	fs.open(filename.c_str(), std::ofstream::out);


		fs <<"#include <iostream>"<<std::endl;
		fs <<"#include <assert.h>"<<std::endl;
		fs <<"#include <string.h>"<<std::endl;
		fs <<"#define FUNC_PARAM char*, const int size, int start"<<std::endl;
		fs <<"typedef void(*PF_RET_VOID)(FUNC_PARAM);" <<std::endl;
		fs <<"void "<<s <<" (" <<"char*, const int size, int start"<<")\n";
		fs <<"{\n";
		fs <<"\t//The is your code\n";
		fs <<"}\n";
		fs << "void test_all(PF_RET_VOID p)	\n{\n\tchar a[] = \"Hello\";\n\tint size = strlen(a);\n\t(*p)(a, size, 0);\n}\n";
		fs << "int main(int argc, char const *argv[])\n{\n\ttest_all("<<s << ");\n\treturn 0;\n}\n";
		fs.close();
	}
	return 0;
}