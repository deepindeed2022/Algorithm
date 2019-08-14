#include <iostream>
#include <cmath>

float sqrt_newton(float a) {
	float error_th = 0.00001;
	float cur = a/2.0f;
	while(std::fabs(cur * cur - a) > error_th) {
		cur = (cur + a/cur) / 2.0f;
	}
	return cur;
}

int sqrt_binary_search(int x) {
	int left = 1, right = x / 2;
	int last_mid; // 记录最近一次 mid
	if (x < 2) {
		return x;
	}
	while(left <= right) {
		const int mid = left + ((right - left) >> 1);
		if(x / mid > mid) { // 不要用 x > mid * mid，会溢出
			left = mid + 1;
			last_mid = mid;
		} else if(x / mid < mid) {
			right = mid - 1;
		} else {
			return mid;
		}
	}
	return last_mid;
}


int main(int argc, char const *argv[])
{
	std::cout << sqrt_newton(10.0f) << std::endl;
	std::cout << sqrt_binary_search(3) << std::endl;
	return 0;
}