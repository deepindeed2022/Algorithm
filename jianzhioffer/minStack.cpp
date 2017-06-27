//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

#include <stack>
using namespace std;

class Solution 
{
private:
	stack<int> _stack, minStack;
public:
    void push(int value) 
    {
	   _stack.push(value);
	   if(minStack.empty()) minStack.push(value);
	   else if(value <= minStack.top())
	   minStack.push(value); 
    }
    void pop() {
        if(_stack.top() == minStack.top())
        	minStack.pop();
        _stack.pop();
    }
    int top() {
        return _stack.top();
    }
    int min() {
        return minStack.top();
    }
};