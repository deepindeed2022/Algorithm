#include <cstring>
#include <iostream>
class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(str == NULL || length < 0)
			return;
		int i = 0;
		int old_len = 0;
		int space_num = 0;
		while(str[i]!='\0')
		{
			old_len++;
			if(str[i]==' ')
			{
				space_num++;
			}
			i++;
		}
		int new_len = old_len + space_num*2;
		if(new_len > length)return;
		int pOld = old_len;
		int pNew = new_len;
		while(pOld >=0 && pNew > pOld)
		{
			if(str[pOld] == ' ')
			{
				str[pNew--]='0';
				str[pNew--]='2';
				str[pNew--]='%';
			}
			else
			{
				str[pNew--] = str[pOld];
			}
			pOld--;
		}

	}
};