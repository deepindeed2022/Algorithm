/**************************************************
 * Implement atoi to convert a string to an integer
 *
 **************************************************/
 #include <climits>
 #include <cassert>
 #include <cstring>
 int atoi(const char* str)
 {
    int num = 0;
    int sign = 1;
    const int n = strlen(str);
    int i = 0;
    //remove black space in the front input
    while(str[i] ==' ' && i < n) i++;
    
    if(str[i] == '+') i++;
    if(str[i] == '-')
    {
        sign = -1; i++;
    }
    
    for(; i < n; i++)
    {
        if(str[i] < '0' || str[i] > '9') break;
        if(num > INT_MAX/10 || (num == INT_MAX/10 && (str[i] - '0') > INT_MAX%10))
        {
            return sign == -1 ? INT_MIN: INT_MAX;
        }
        num = num*10 + str[i]-'0';
    }
    return num*sign;
 }

void test_atoi()
{
    assert(atoi("1234567") == 1234567);
    assert(atoi("  -100") == -100);
    assert(atoi("") == 0);
    assert(atoi("1234a234") == 1234);
    assert(atoi("+ 234") == 0);
    assert(atoi("++1") == 0);

    assert(atoi("  +214748364777") == 2147483647);
    assert(atoi("  +214748364777    ") == 2147483647);
    assert(atoi("  -214748364777") == -2147483648);
}
int main(int argc, char const *argv[])
{
    test_atoi();
    return 0;
}