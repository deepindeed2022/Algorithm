#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////
// reverse a string between two pointers
// Input: pBegin - the begin pointer in a string
//        pEnd   - the end pointer in a string
///////////////////////////////////////////////////////////////////////
void reverse(char *pBegin, char *pEnd)
{
	if (pBegin == NULL || pEnd == NULL) return;

	while (pBegin < pEnd) {
		char temp = *pBegin;
		*pBegin   = *pEnd;
		*pEnd     = temp;
		pBegin++, pEnd--;
	}
}

///////////////////////////////////////////////////////////////////////
// reverse the word order in a sentence, but maintain the character
// order inside a word
// Input: pData - the sentence to be reversed
///////////////////////////////////////////////////////////////////////
char *reverse_sentence(char *pData) {
	if (pData == NULL)
		return NULL;

	char *pBegin = pData;
	char *pEnd   = pData;

	while (*pEnd != '\0') pEnd++;
	pEnd--;

	// reverse the whole sentence
	reverse(pBegin, pEnd);

	// reverse every word in the sentence
	pBegin = pEnd = pData;
	while (*pBegin != '\0') {
		if (*pBegin == ' ') {
			pBegin++;
			pEnd++;
			continue;
		}
		// A word is between with pBegin and pEnd, reverse it
		else if (*pEnd == ' ' || *pEnd == '\0') {
			reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		} else {
			pEnd++;
		}
	}

	return pData;
}

int main(int argc, char* argv[]) {
	char source[] = "Hello, I am a student!";
	cout << source << "\n";

	cout << reverse_sentence(source) << "\n";
	return EXIT_SUCCESS;
}