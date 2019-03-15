#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
class highPercisionDigit
{
public:
    vector<int> increment(vector<int>& digits, int plus)
    {
        this->add(digits, plus);
        return digits;
    }
    vector<int> decrement(vector<int>& digits, int digit)
    {
        this->sub(digits, digit);
        return digits;
    }
private:
    void add(vector<int>& digits, int digit)
    {
        int carry = digit;
        for(std::vector<int>::reverse_iterator it = digits.rbegin(); carry > 0 && it != digits.rend();++it)
        {
            *it += carry;
            carry = *it / 10;
            *it %= 10;
        }
        if(carry > 0)
            digits.insert(digits.begin(), 1);
    }

    void sub(vector<int>& digits, int digit)
    {
        assert(digit <= 9);
        assert(digit >= 1);
        int size = digits.size();
        size--;
        digits[size] -= digit;
        while(size >= 0 && digits[size] < 0)
        {
            digits[size] += 10;
            size--;
            digits[size] -= 1;
        }

        while(*digits.begin() == 0)
        {
            digits.erase(digits.begin());
        }
    }
};
void test_highPercisionDigit()
{
    int digit = 1;
    std::vector<int> digits(9, 9);
    highPercisionDigit h;
    std::vector<int> result = h.increment(digits, digit);
    for(int i = 0 ; i < result.size(); ++i)
    {
        std::cout << result[i];
    }
    std::cout << std::endl;
       
    result = h.decrement(result, digit);
    for(int i = 0 ; i < result.size(); ++i)
    {
        std::cout << result[i];
    }
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    test_highPercisionDigit();
    return 0;
}