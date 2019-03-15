//求next 数组求法
#include <iostream>
#include <string.h>
int* next = new int[10];  
void GetNextval(char* p, int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀    
        if (k == -1 || p[j] == p[k])  
        {  
            ++j;  
            ++k;  
            //较之前next数组求法，改动在下面4行  
            if (p[j] != p[k])  
                next[j] = k;   //之前只有这一行  
            else  
                //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
                next[j] = next[k];  
        }  
        else  
        {  
            k = next[k];  
        } 
    } 

}
int Search(char* s, char* p)  
{  
    int i = 0;  
    int j = 0;  
    int sLen = strlen(s);  
    int pLen = strlen(p);
    int maxlenth=0;  
    while (i < sLen && j < pLen)  
    {  
        //如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
        if (j == -1 || s[i] == p[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            //如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
            //next[j]即为j所对应的next值        
            j = next[j];
            if(maxlenth<j-next[j])
                maxlenth = j-next[j];  
        }  
    }  
    return maxlenth;  
}  

int main(int argc, char const *argv[])
{
    char a[] = "acaccbabb";
    char b[]="acbac";
    GetNextval(b,next);
    std::cout<<Search(a,b)<<std::endl;
    return 0;
}
