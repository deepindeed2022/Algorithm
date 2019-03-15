class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size()) return false;
        vector<int> stack;
        for(int i = 0, j = 0; i < pushV.size();)
        {
        	stack.push_back(pushV[i++]);
        	while(j < popV.size() && stack.back() == popV[j])
        	{
        		stack.pop_back();
        		j++;
        	}
        }
        return stack.empty();
    }
};