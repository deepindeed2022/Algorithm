#include <iostream>
#include <vector>
int remove_duplicate(int a[], const int size) {
	if(size <= 1) return size;
	int index = 1;
	for(int i = 1; i < size; i++) {
		if(a[index] != a[i])
			a[index++] = a[i];
	}
	return index;
}
int main(int argc, char const *argv[])
{
	int a[] = {1, 1, 2};
	int r = remove_duplicate(a, 3);
	std::cout << r << std::endl;	
	r = remove_duplicate(a, 2);
	std::cout << r << std::endl;
	return 0;
}