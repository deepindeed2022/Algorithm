#include <stdio.h>
#include <stdlib.h>
class ListNode
{
public:
	ListNode* next;
	int value;
	ListNode():value(-1),next(NULL){}
	ListNode(int _val)
	{
		value = _val;
		next = NULL;
	}
	ListNode(int _val, ListNode* _next)
	{
		next = _next;
		value = _val;
	}
};

ListNode* reverseList(ListNode* pHead)
{
	ListNode* pReverseHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;

	while(pNode != NULL)
	{
		ListNode* pNext = pNode->next;
		if(pNext == NULL) pReverseHead = pNode;

		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	
	return pReverseHead;
}

ListNode* init(int init_val)
{
	ListNode* headpre = new ListNode();
	ListNode* curr = headpre;
	for(int i = 0; i < init_val; i++)
	{
		curr->next = new ListNode(i);
		curr = curr->next;
	}
	//printf("%d\n", headpre->next->value);
	return headpre->next;
}
void print_list(ListNode* head)
{
	ListNode* curr = head;
	while(curr != NULL)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
	return;
}
int main(int argc, char const *argv[])
{
	ListNode* head = init(10);
	print_list(head);
	//printf("%d\n", head->value);
	ListNode* result = reverseList(head);
	//printf("%d\n", head->value);
    print_list(result);
	return 0;
}