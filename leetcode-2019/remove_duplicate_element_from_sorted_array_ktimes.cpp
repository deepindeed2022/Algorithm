#include <iostream>
#include <vector>

int remove_duplicate(int a[], const int size, const int k=1) {
	if(size <= 1) return size;
	int index = k;
	for(int i = k; i < size; i++) {
		if(a[index - k] != a[i])
			a[index++] = a[i];
	}
	return index;
}

int main(int argc, char const *argv[])
{
	int a[] = {1, 1, 2, 2, 2, 3};
	int r = remove_duplicate(a, 6, 2);
	std::cout << r << std::endl;
	r = remove_duplicate(a, 4, 2);
	std::cout << r << std::endl;
	return 0;
}