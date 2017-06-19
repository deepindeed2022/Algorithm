#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) 
    {
    	this->stack1.push(node);    
    }

    int pop() 
    {
    	if(!this->stack2.empty())
    	{
    		int result = this->stack2.top();
    		this->stack2.pop();
    		return result;
    	}
    	else if(this->stack1.empty())
    	{
    		return NULL;
    	}
    	else
    	{
    		while(!this->stack1.empty())
    		{
    			this->stack2.push(this->stack1.top());
    			this->stack1.pop();
    		}
    		int result = this->stack2.top();
    		this->stack2.pop();
    		return result;
    	}
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};