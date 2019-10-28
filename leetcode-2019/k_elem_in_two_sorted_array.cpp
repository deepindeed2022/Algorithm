#include <vector>
#include <iostream>

int sorted_array_kth_value(int* a, int a_size, int* b, int b_size, int k) {
	if(!(a_size >= 0 && b_size >= 0 && k > 0 && k <= a_size + b_size)) return INT32_MIN;


}

int two_sorted_array_kth_value(std::vector<int>& a, std::vector<int>& b, const int k) {
	int a_start = 0;
	int b_start = 0;
	int a_end = a.size();
	int b_end = b.size();
	while(a_start < a_end && b_start < b_end) {
		int a_mid = (a_start + a_end) / 2;
		int b_mid = (b_start + b_end) / 2;
		if(a[a_mid] < b[b_mid]) {
			b_end = b_mid - 1;
		} else if(a[a_mid] > b[b_mid]) {
			a_end = a_mid - 1;
		} else {
			return a[a_mid];
		}
	}
}


int main(int argc, char const *argv[])
{
	std::vector<int> a = {1, 3, 5, 7, 9};
	std::vector<int> b = {2, 4, 6, 8, 10};
	std::cout << two_sorted_array_kth_value(a, b, 7) << std::endl;
	return 0;
}