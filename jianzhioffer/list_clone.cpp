
// 链接：https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba



struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


    /*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
    */
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        // 复制节点，让后插入到原来节点的后面    
        RandomListNode* currNode = pHead;
        while(currNode)
        {
        	RandomListNode* node = new  RandomListNode(currNode->label);
        	node->next = currNode->next;
        	currNode->next = node;
        	// 在原list中走
        	currNode = node->next;
        }
        // 遍历链表，复制random指针
        currNode = pHead;
        while(currNode)
        {
        	RandomListNode* node = currNode->next;
        	if(currNode->random)
        	{
        		node->random = currNode->random->next;
        	}
        	currNode = node->next;
        }

        // 拆开链表
		RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while(currNode->next){
            tmp = currNode->next;
            currNode->next =tmp->next;
            currNode = tmp;
        }
        return pCloneHead;
    }
};