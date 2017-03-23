//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#include <climits>
// 直接利用原始的数据，重新设置指针的后继就可；
// 采用头节点的方法，进行记录最后返回的位置为头节点的next
// 然后采用传统的merge方法就可以了
// 注意的是，对于当一个链表到达尾的时候，我们采用最大值的方式
// 赋值为最大值的方式进行比较，从而继续合并
// 其实，当一个为空的时候时候，另外一个list只需要挂上就好了
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        for(ListNode* p = &head; l1 != NULL || l2 != NULL; p = p->next)
        {
            int val1 = l1 == NULL ? INT_MAX: l1->val;
            int val2 = l2 == NULL ? INT_MAX: l2->val;
            if(val1 <= val2)
            {
                p->next = l1; 
                l1 = l1->next;
                if(l2 == NULL) break;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
                if(l1 == NULL) break;
            }
            
        }
        return head.next;
    }
};