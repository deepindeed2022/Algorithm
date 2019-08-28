#include <vector>
#include <iostream>

int two_sorted_array_kth_value(std::vector<int>& a, std::vector<int>& b, const int k) {
	int a_start = 0;
	int b_start = 0;
	int a_end = a.size();
	int b_end = b.size();
	while(a_start < a_end && a_end < a_end) {
		int a_mid = (a_start + a_end) / 2;
		int b_mid = (b_start + b_end) / 2;
		if(a[a_mid] < b[b_mid]) {
			b_end = b_mid - 1;
		} else if(a[a_mid] > b[b_mid])
			a_end = a_mid - 1;
		} else {
			return a[a_mid];
		}
	}
}


int main(int argc, char const *argv[])
{
	
	return 0;
}