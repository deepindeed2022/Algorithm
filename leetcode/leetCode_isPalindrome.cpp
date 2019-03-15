#include <iostream>
#include <string>
#include <iterator>
#include <cassert>
bool isPalindrome(std::string s);
void test_isPalindrom()
{
	assert(isPalindrome("1234567890987654321"));
	assert(isPalindrome("abcCBA"));
	assert(!isPalindrome("asjflangjnakjg"));
	assert(isPalindrome("oooLilOOO"));
	assert(isPalindrome("A man, a plan, a canal: Panama"));
}

int main(int argc, char const *argv[])
{
	std::string a="ooooolLlLooOoo";
	std::cout << a <<std::endl;
	std::cout << std::boolalpha << isPalindrome(a) << std::endl;
	test_isPalindrom();
	return 0;
}
bool isPalindrome(std::string s)
{
	for (std::string::iterator i = s.begin(); i != s.end(); ++i)
	{
		*i = std::tolower(*i);
	}
	std::string::iterator left = s.begin(), right = s.end();
	--right;
	while(left<right)
	{
		if(!std::isalnum(*left)) 
			++left;
		else if(!std::isalnum(*right)) 
			--right;
		else if(*left != *right)
			return false;
		else
		{
			++left;
			--right;
		}
	}
	return true;
}
bool isPalindrome(int num)
{
	string a(to_string(num));
}