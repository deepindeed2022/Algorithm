/**
 * \brief 
 Given a string containing just the characters ’(’ and ’)’, find the length of the longest valid (wellformed) parentheses substring.
For ”(()”, the longest valid parentheses substring is ”()”, which has length = 2.
Another example is ”)()())”, where the longest valid parentheses substring is ”()()”, which has
length = 4
**/

#include <string>
#include <stack>
#include <cassert>
#include <iostream>
#define max(x, y)  x >= y ? x: y
using namespace std;
int longest_valid_parentheses(std::string s)
{
	int max_len = 0;
	int last = -1;
	std::stack<int> lefts;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '(')
		{
			lefts.push(i);
		}
		else
		{
			if(lefts.empty())
			{
				last = i;
			}
			else
			{
				lefts.pop();
				if(lefts.empty())
				{
					max_len = max(max_len, i - last);
				}
				else
				{
					max_len = max(max_len, i - lefts.top());
				}
			}
		}
	}
	return max_len;
}

void test_longest_valid_parentheses()
{
	string str1 = ")()())";

	assert(longest_valid_parentheses(str1) == 4);
	assert(longest_valid_parentheses("(()") == 2);

}
int main(int argc, char const *argv[])
{
	test_longest_valid_parentheses();	
	return 0;
}