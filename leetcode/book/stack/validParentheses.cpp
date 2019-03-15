/**
 * \brief Given a string containing just the characters ’(’, ’)’, ’{’, ’}’, ’[’ and ’]’, determine if the
 * input string is valid.
 * The brackets must close in the correct order, ”()” and ”()[]” are all valid but ”(]” and ”([)]” are
 * not
 * \author:
 * \create time
**/

#include <string>
#include <stack>
#include <cassert>
#include <iostream>
 
using namespace std;

bool isValid(string const& s)
{
	string left = "([{";
	string right = ")]}";
	std::stack<char> stk;
	for(auto c: s)
	{
		if(left.find(c) != string::npos)
		{
			stk.push(c);
		}
		else
		{
			if(stk.empty() || stk.top() != left[right.find(c)])
				return false;
			else
				stk.pop();
		}
	}
	return stk.empty();
}
void test_isValid()
{
	string validstr = "{}{[()()]}";
	string invalidstr1 = "{}{[(a)()]}";
	string invalidstr2 = "({}{[())]}";
	assert(isValid(validstr));
	assert(!isValid(invalidstr1));
	assert(!isValid(invalidstr2));

}
int main(int argc, char const *argv[])
{
	test_isValid();	
	return 0;
}