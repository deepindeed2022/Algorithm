#include <string>
#include <iostream>
using namespace std;

int lengthOfLastWord(string s) {
    int l = s.size();
    int no_space_idx = -1;
    int i = l - 1;
	while(i >= 0 && isspace(s[i])) i--;
	if(i < 0) return 0;
	no_space_idx = i;
	while(i >= 0 && !isspace(s[i])) i--;
	return no_space_idx - i;
}

int main(int argc, char const *argv[]) {
	std::cout << lengthOfLastWord("hello world") << std::endl;
	return 0;
}