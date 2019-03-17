#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include "lrucache.h"
void lru_test(int capacity = 16)
{
	LRUCache * caches = new LRUCache(capacity);

	int tmp = 0;
	int size = capacity*2;
	for (int i = 0; i < size; i++)
	{
		tmp = powf(i, 2);
		// fprintf(stderr, "%d %d\n", i, tmp);
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
int main(int argc, char* argv[])
{
	lru_test(8);

	return EXIT_SUCCESS;
}