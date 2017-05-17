#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool wordBreak(string s, unordered_set<string>& dict)
{
	vector<bool> f(s.size() + 1, false);
	f[0] = true;
	for(int i = 1; i <= s.size(); ++i)
	{
		for(int j = i -1; j >= 0; --j)
		{
			if(f[j] && dict.find(s.substr(j, i-j)) != dict.end())
			{
				f[i] = true;
				break;
			}
		}
	}
	return f[s.size()];
}
int main(int argc, char const *argv[])
{
	
	return 0;
}
