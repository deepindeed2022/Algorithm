#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////
// Reverse a string between two pointers
// Input: pBegin - the begin pointer in a string
//        pEnd   - the end pointer in a string
///////////////////////////////////////////////////////////////////////
void Reverse(char *pBegin, char *pEnd)
{
   if (pBegin == NULL || pEnd == NULL)
      return;

   while (pBegin < pEnd)
   {
      char temp = *pBegin;
      *pBegin   = *pEnd;
      *pEnd     = temp;

      pBegin++, pEnd--;
   }
}

///////////////////////////////////////////////////////////////////////
// Reverse the word order in a sentence, but maintain the character
// order inside a word
// Input: pData - the sentence to be reversed
///////////////////////////////////////////////////////////////////////
char *ReverseSentence(char *pData)
{
   if (pData == NULL)
      return NULL;

   char *pBegin = pData;
   char *pEnd   = pData;

   while (*pEnd != '\0') pEnd++;
   pEnd--;

   // Reverse the whole sentence
   Reverse(pBegin, pEnd);

   // Reverse every word in the sentence
   pBegin = pEnd = pData;
   while (*pBegin != '\0')
   {
      if (*pBegin == ' ')
      {
         pBegin++;
         pEnd++;
         continue;
      }
      // A word is between with pBegin and pEnd, reverse it
      else if (*pEnd == ' ' || *pEnd == '\0')
      {
         Reverse(pBegin, --pEnd);
         pBegin = ++pEnd;
      }
      else
      {
         pEnd++;
      }
   }

   return pData;
}
int main()
{
   char source[] = "Hello, I am a student!";
   cout << source << "\n";

   cout << ReverseSentence(source) << "\n";
   return 1;
}