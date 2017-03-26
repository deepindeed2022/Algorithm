#include <cassert>
#include <cstdio>
struct ListNode {
   struct ListNode *next;
   int data;
   ListNode() : data(0), next(NULL) {}
   ListNode(int _data) : data(_data), next(NULL) {}
   ~ListNode() { delete next; }
};

void initCircleList(ListNode **head);
void initNoCircleList(ListNode **head);
void free_list(ListNode **head);
bool existCircle(ListNode *llist);
int main(int argc, char const *argv[]) {
   ListNode *h;
   initNoCircleList(&h);
   assert(false == existCircle(h));

   // h = NULL;
   initCircleList(&h);
   assert(true == existCircle(h));

   return 0;
}
void initCircleList(ListNode **head) {
   ListNode *temp = new ListNode(1);

   *head = temp;
   temp = new ListNode(3);
   (*head)->next = temp;

   ListNode *temp1 = new ListNode(5);
   temp1->next = *head;
   temp->next = temp1;
}
void initNoCircleList(ListNode **head) {
   ListNode *temp = new ListNode(1);
   *head = temp;

   temp = new ListNode(3);
   (*head)->next = temp;

   ListNode *temp2 = new ListNode(5);
   temp->next = temp2;
}
void free_list(ListNode **head) {
   ListNode *pre = *head;
   ListNode *next = NULL;
   while (pre->next) {
      next = pre->next;
      delete pre;
      pre = next;
   }
   delete pre;
}
bool existCircle(ListNode *llist) {
   ListNode *pfast = llist;
   ListNode *pslow = llist;

   while (true) {
      if (pfast && pfast->next)
         pfast = pfast->next->next;
      else
         return false;

      pslow = pslow->next;
      if (pslow == pfast)
         break;
   }
   return true;
}