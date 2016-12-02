#include <vector>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	# if defined(__sgi)
	std::cout << "_sgi" << std::endl;
	# endif
	# if defined(__GNUC__)
	std::cout << "__GNUC__" << std::endl;
	std::cout << __GNUC__ <<' ' <<__GNUC_MINOR__ <<std::endl;
	#endif

	#ifdef __STL_NO_DRAND48
	std::cout << "__STL_NO_DRAND48 defined" <<std::endl;
	#else
	std::cout << "__STL_NO_DRAND48 undefined" <<std::endl;
	#endif

	#ifdef __STL_STATIC_TEMPLATE_MEMBER_BUG
	std::cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG defined"<<std::endl;
	#else
	std::cout <<"__STL_STATIC_TEMPLATE_MEMBER_BUG undefined"<<std::endl;
	#endif
	return 0;
}