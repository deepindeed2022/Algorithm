#include "stdheader.h"

using std::unordered_map;

class LRUCache
{
private:
    struct BlockNode
    {
        int key;
        int val;
        BlockNode * prev;
        BlockNode * next;
        BlockNode(int key_, int val_) : key(key_), val(val_), prev(NULL), next(NULL) {}
    };
    
    BlockNode * head;
    BlockNode * tail;
    int size;
    int count;
    std::unordered_map<int, BlockNode *> blocks;
    
    BlockNode * findNode(int key)
    {
        auto it = blocks.find(key);
        if(it != blocks.end())
        {
            return it -> second;
        }
        else
        {
            return NULL;
        }
    }
    void insertToTail(BlockNode * ptr)
    {
        BlockNode * prev = tail -> prev;
        prev -> next = ptr;
        ptr -> next = tail;
        tail -> prev = ptr;
        ptr -> prev = prev;
    }
    void moveToTail(BlockNode * ptr)
    {
        if(tail == ptr -> next)
            return;
        BlockNode * prev = ptr -> prev;
        BlockNode * next = ptr -> next;
        prev -> next = next;
        next -> prev = prev;
        insertToTail(ptr);
    }
    
public:
    LRUCache(int capacity)
    {
        head = new BlockNode(0, 0);
        tail = new BlockNode(0, 0);
        head -> next = tail;
        tail -> prev = head;
        size = capacity;
        count = 0;
    }
    ~LRUCache()
    {
        for(auto it = blocks.begin(); it != blocks.end(); it ++)
            delete it -> second;
        delete head;
        delete tail;
    }
    
    int get(int key)
    {
        BlockNode * ptr = findNode(key);
        if(NULL == ptr)
        {
            return -1;
        }
        else
        {
            moveToTail(ptr);
            return ptr -> val;
        }
    }
    
    void set(int key, int value)
    {
        BlockNode * ptr = findNode(key);
        if(NULL != ptr)
        {
            ptr -> val = value;
            moveToTail(ptr);
        }
        else
        {
		
            if(count < size)
            {
                count ++;
                BlockNode * ptr = new BlockNode(key, value);
                blocks[key] = ptr;
                insertToTail(ptr);
            }
            else
            {
				// if the blocklist number have exceed the capacity of replace 
				// the non-LRU block information
                BlockNode * ptr = head -> next;
                blocks.erase(ptr -> key);
                blocks[key] = ptr;
                ptr -> key = key;
                ptr -> val = value;
                moveToTail(ptr);
            }
        }
    }
};