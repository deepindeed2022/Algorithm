#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_block* t_block;
struct s_block
{
	size_t size;
	t_block next;
	t_block prev;
	int free;
	void * ptr;
	char data[1];
}
// use for bit align
#define align4(x) (((((x) -1) >> 2) << 2) + 4)


#define BLOCK_SIZE 12
//Because we 
//#define BLOCK_SIZE sizeof(struct s_block)

t_block base = NULL; // the starting point of our process heap
t_block find_block(t_block* last, size_t size);
t_block extend_heap(t_block last, size_t s);
void split_block(t_block b, size_t s);
void* malloc(size_t size);
void free(void *p);

int main()
{
	int count, *array;
	if((array = (int*)malloc(10*sizeof(int))) == NULL)
	{
		printf("Cannot alloct memory space!");
		exit(1);
	}
	for( count = 0; count < 10; count ++)
	{
		array[count] = count;
	}
	for( count = 0; count < 10; count ++)
		printf("%2d",array[count]);
        printf("\n");	
	malloc(array);
	count = 0;	
	while(++count < 1000)
	{
		printf("%d time allocation\n", count);
		if((array = (int*)malloc(10*1024*1024)) == NULL)
		{
			printf("Alloca memory failed");
		}
		free(array);
	}
	return 1;
}


void *malloc(size_t size)
{
	t_block b,last;
	size_t s;
	s = align4(size);
	if (base) 
	{
		/* First find a block */
		last = base;
		b = find_block(&last ,s);
		if (b) 
		{
			/* can we split */
			if ((b->size - s) >= (BLOCK_SIZE + 4))
			split_block(b,s);
			b->free=0;
		} 
		else 
		{
			/* No fitting block , extend the heap */
			b = extend_heap(last ,s);
			if (!b)
			return(NULL);
		}
	} else {
		/* first time */
		b = extend_heap(NULL ,s);
		if (!b)
		return(NULL);
		base = b;
	}
	return(b->data);
}

t_block find_block(t_block* last, size_t size)
{
	t_block b = base;
	while(b && !(b->free && b->size >= size))
	{
		*last = b;
		b = b->next;
	}
	return b;
}
t_block extend_heap(t_block last, size_t s)
{
	t_block b;
	b = sbrk(0);
	if(sbrk(BLOCK_SIZE + s) == (void*)-1)
	{
		return NULL;
	}
	b->size = s;
	b->next = NULL;
	if(last)
		last->next = b;
	b->free = 0; //means block b have been used by process
	return b;
}
void split_block(t_block b, size_t s)
{
	t_block new;
	new = b->data + s;
	new->size = b->size - s - BLOCK_SIZE;
	new->next = b->next;
	new->free = 1;
	b->size = s;
	b->next = new;
}


///////////////////////////////////////////////////////////////////////
t_block fusion(t_block b)
{
	if(b->next && b->next->free)
	{
		b->size += BLOCK_SIZE + b->next->size;
		b->next = b->next->next;
		if(b->next)
		{
			b->next->prev = b;
		}
		return b;
	}
}
t_block get_block(void* p)
{
	char* tmp;
	tmp = p;
	return (p= tmp -= BLOCK_SIZE);
}
int valid_addr(void* p)
{
	if( base)
	{
		if (p > base && p < sbrk(0))
		{
			return (p == (get_block(p))->ptr);
		}
	}
	return 0;
}
/* The free */
/* See free(3) */
void free(void *p)
{
	t_block b;
	if (valid_addr(p))
	{
		b = get_block(p);
		b->free = 1;
		/* fusion with previous if possible */
		if(b->prev && b->prev ->free)
			b = fusion(b->prev);
		/* then fusion with next */
		if (b->next)
			fusion(b);
		else
		{
			/* free the end of the heap */
			if (b->prev)
			b->prev ->next = NULL;
			else
			/* No more block !*/
			base = NULL;
			brk(b);
		}
	}
}
