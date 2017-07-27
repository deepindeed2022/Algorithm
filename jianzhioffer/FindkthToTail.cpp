struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	ListNode* fast = pListHead;
    	int i = k;
    	while(fast && i > 0)
    	{
    		fast = fast->next;
    		i--;
    	}
    	if(i != 0) return NULL;

    	ListNode* slow = pListHead;
    	while(fast && slow)
    	{
    		fast  = fast->next;
    		slow = slow->next;
    	}
    	return slow;
    }
};