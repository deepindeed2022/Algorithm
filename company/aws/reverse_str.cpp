#include <stdio.h>

// 自定义swap函数,方法一
void swap(char* l, char* r)
{
	char tmp = *l;
	*l = *r;
	*r = tmp;
}
// std::swap的实现方式
void swap(char& l, char& r)
{
	char tmp = l;
	l = r;
	r = tmp;
}
// 将一个词进行翻转
void reverse(char *pBegin, char *pEnd)
{
	if(pBegin == NULL || pEnd == NULL)
		return;
	
	while(pBegin < pEnd)
	{
        swap(*pBegin, *pEnd);
		// char temp = *pBegin;
		// *pBegin = *pEnd;
		// *pEnd = temp;
		pBegin ++, pEnd --;
	}
}
// 主函数，进行对句子中进行翻转
char* reverse_sentence(char *pData)
{
	if(pData == NULL) return NULL;
	
	char *pBegin = pData;
	// 获取字符串结尾的位置
	char *pEnd = pData;
	while(*pEnd != '\0') pEnd ++;
	pEnd--;
	
	// 翻转真个
	reverse(pBegin, pEnd);
	
	pBegin = pEnd = pData;
	while(*pBegin != '\0')
	{
		//跳过空格
		if(*pBegin == ' ')
		{
			pBegin ++;
			pEnd ++;
			continue;
		}
		// A word is between with pBegin and pEnd, reverse it
		else if(*pEnd == ' ' || *pEnd == '\0')
		{
			reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd ++;
		}
	}
	return pData;
}
int main(int argc, char* argv[])
{
	char  a[] = "This is a great dog.";
	reverse_sentence(a);
	printf("%s\n", a);
	// printf("%s\n", b);
	return 0;
}