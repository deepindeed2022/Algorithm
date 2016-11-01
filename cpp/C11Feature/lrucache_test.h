#include "lrucache.h"
#include <cmath>
#include <cassert>
void lru_test(int capacity = 16)
{
	LRUCache * caches = new LRUCache(capacity);

	int tmp = 0;
	int size = capacity*2;
	for (int i = 0; i < size; i++)
	{
		tmp = pow<int>(i, 2);
		caches->set(i, tmp);
		assert(caches->get(i) == tmp);
	}
	for (int i = 0; i < capacity; i++)
	{
		assert( -1 == caches->get(i));
	}
	for (int i = capacity; i < size; i++)
	{
		std::cout << caches->get(i) << std::endl;
	}
	delete caches;
}