/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        else if(pHead2 == NULL) return pHead1;
        else
        {
            ListNode* head = NULL;
            ListNode* curr = NULL;
            if(pHead1->val > pHead2->val) 
            {
                head = pHead2;
                pHead2 = pHead2->next;
            }
            else 
            {
                head = pHead1;
                pHead1 = pHead1->next;
            }
            curr = head;
            while(pHead1 && pHead2)
            {
                if(pHead1->val > pHead2->val) 
                {
                    curr->next = pHead2;
                    pHead2 = pHead2->next;
                }
                else 
                {
                    curr->next = pHead1;
                    pHead1 = pHead1->next;
                }
                curr = curr->next;
            }
            if(pHead1)
            {
                curr->next = pHead1;
            }
            else
            {
                curr->next = pHead2;
            }
            return head;
        }
        
    }
};