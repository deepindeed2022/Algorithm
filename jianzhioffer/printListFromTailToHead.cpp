/**
* 输入一个链表，从尾到头打印链表每个节点的值。
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        while(head != NULL)
        {
        	v.push_back(head->val);
        	head = head->next;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};