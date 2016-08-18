#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void* m_malloc(long nbytes);
void m_free(void* headbyte);

int isInitialized = 0;
void *managed_addr_head;
void *valid_addr_tail;

void malloc_init()
{
	//grab the last valid address from OS
	valid_addr_tail = sbrk(0);
	// we don't have any menory to manage yet, so just set
	// the beginning to be the valid_addr_tail;
	managed_addr_head = valid_addr_tail;
	// OK, we're initialized and read to go
	isInitialized = 1;
}

typedef struct mem_control_block
{
	int isAvailable;
	int size;
}MEM_CONTROL_BLOCK;


int main()
{
	int count, *array;
	if((array = (int*)m_malloc(10*sizeof(int))) == NULL)
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
	m_malloc(array);
	count = 0;	
	while(++count < 1000)
	{
		printf("%d time allocation\n", count);
		if((array = (int*)m_malloc(10*1024*1024)) == NULL)
		{
			printf("Alloca memory failed");
		}
		m_free(array);
	}
	return 1;
}
void m_free(void* headbyte)
{
	struct mem_control_block* mcb;
	// backup from the given pointer to find the mem_control_block
	mcb = headbyte - sizeof(struct mem_control_block);
	// mark the block as being available
	mcb->isAvailable = 1;
	return;
}

void* m_malloc(long nbytes)
{
	void* current_location;//hold the memory site
	// this is the current location's mcb
	struct mem_control_block* current_location_mcb;
	// this is the memeory location we will return,
	// It will be set to 0 until we find something suitable
	void* memory_location;
	//initialize if we haven't already done so
	if(!isInitialized)
	{
		malloc_init();
	}
	// the memory we search for has to include the memory control block,
	// but the users of malloc don't need to know this, so we'll just
	// add it in for them
	nbytes = nbytes + sizeof(struct mem_control_block);

	//set memory_location to 0 until we find a suitable location
	memory_location = 0;
	//begin searching at the start of managed memory
	current_location = managed_addr_head;
	// keep going until we have searched all allocated space
	while(current_location != valid_addr_tail)
	{
		/* current_location and current_location_mcb point
		 * to the same address.  However, current_location_mcb
		 * is of the correct type, so we can use it as a struct.
		 * current_location is a void pointer so we can use it
		 * to calculate addresses.
		 */
		current_location_mcb = (struct mem_control_block*)current_location;
		if(current_location_mcb->isAvailable)
		{
			if(current_location_mcb->size >= nbytes)
			{
				//Have found an open,appropriately-size location
				//It is no longer availabe 
				current_location_mcb->isAvailable = 0;
				memory_location = current_location;
				break;
			}

		}

		//If we made it hear, it's because the current memory block
		// not suitable; move to the next one
		current_location = current_location + current_location_mcb->size;
	}//end while

	// if we still don't have a valid location, we'll have
	// to ask the operating system for more memory
	if(! memory_location)
	{
		//move the program break nbytes futher
		sbrk(nbytes);
		//the new memory will be where the last valid addr left off
		memory_location = valid_addr_tail;
		//we'll move the last valid address forward nbytes
		valid_addr_tail = valid_addr_tail + nbytes;
		
		//we need to initialize the mem_control_block;
		current_location_mcb =(struct mem_control_block*) memory_location;
		current_location_mcb->isAvailable = 0;
		current_location_mcb->size = nbytes;
	}
	/* Now, no matter what (well, except for error conditions),
	 * memory_location has the address of the memory, including
	 * the mem_control_block
	 */
	//Move the pointer past the mem_control_block
	 memory_location = memory_location + sizeof(struct mem_control_block);
	 return memory_location;
}
