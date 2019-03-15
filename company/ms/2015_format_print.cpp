// For this question, your program is required to process an input string containing only ASCII characters between ‘0’ and ‘9’, or between ‘a’ and ‘z’ (including ‘0’, ‘9’, ‘a’, ‘z’).
// Your program should reorder and split all input string characters into multiple segments, and output all segments as one concatenated string. The following requirements should also be met,

// 1. Characters in each segment should be in strictly increasing order. For ordering, ‘9’ is larger than ‘0’, ‘a’ is larger than ‘9’, and ‘z’ is larger than ‘a’ (basically following ASCII character order).
// 2. Characters in the second segment must be the same as or a subset of the first segment; and every following segment must be the same as or a subset of its previous segment.

// Your program should output string “” when the input contains any invalid characters (i.e., outside the ’0′-’9′ and ‘a’-’z’ range).

// # Input
// Input consists of multiple cases, one case per line. Each case is one string consisting of ASCII characters.
// # Output
// For each case, print exactly one line with the reordered string based on the criteria above.
// #样例输入
// 　　aabbccdd
// 　　007799aabbccddeeff113355zz
// 　　1234.89898
// 　　abcdefabcdefabcdefaaaaaaaaaaaaaabbbbbbbddddddee
// #样例输出
// 　　abcdabcd
// 　　013579abcdefz013579abcdefz

// 　　abcdefabcdefabcdefabdeabdeabdabdabdabdabaaaaaaa
#include <stdint.h>
#include <cstring>
#include <string>
#include <memory>
#include <cstdlib>
#include <iostream>
using std::cin;
using namespace std;
int main(int argc, char const *argv[])
{
	uint32_t table[128];
	std::string str;
	while(std::cin >> str)
	{
		//init
		memset(table, 0, 128 * 4);
		//check string
		int i = 0;
		int max_size = 0;
		while(str[i])
		{
			char c = str[i];
			if(isdigit(c)|| isalpha(c))
			{
				table[c] += 1;
				max_size = max_size < table[c] ? table[c]: max_size;
			}
			else
			{
				std::cout<<std::endl;
				continue;
			}
			i++;
		}

		for(int t = 0; t < max_size; ++t)
			for(char c = '0'; c <= 'z'; ++c)
			{
				if(table[c] > 0)
				{
					std::cout<< (char)c;
					table[c] -= 1;
				}
			}
		std::cout << std::endl;
	}
	return 0;
}