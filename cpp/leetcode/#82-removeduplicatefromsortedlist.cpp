#include <iostream>
#include <cstdlib>
#include <memory>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(!head) return 0;
    if(!head->next) return head;

    int val  = head->val;
    ListNode*p = head->next;

    if(p->val != val)
    {
        head->next = deleteDuplicates(p);
        return head;
    }
    else
    {
        while(p && p->val == val) p = p->next;
        return deleteDuplicates(p);
    }
}

void test_deleteDuplicates()
{
    ListNode* head  = new ListNode(0);
    ListNode* current = head;
    current->next = new ListNode(1);
    current = current->next;
    current->next = new ListNode(1);
    current = current->next;
    current->next = new ListNode(3);
    current = current->next;
    current = deleteDuplicates(head);
    while(current)
    {
        std::cout << current->val<<"->";
        current = current->next;
    }
}
int main(int argc, char const *argv[])
{
    test_deleteDuplicates();
    return 0;
}