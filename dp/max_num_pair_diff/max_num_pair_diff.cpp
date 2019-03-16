//数对之差是一个数字减去它右边的数字。
#include <fstream>
#include <iostream>
using namespace std;

int maxDiff_1(int arr[], const int length);
int maxDiff_2(int arr[], const int length);
int maxDiff_3(int arr[], const int length);

int main(int argc, char const* argv[]) {
	const char infile[] = "input.txt";
	ifstream cin(infile);
	int size = 0;
	cin >> size;
	int* arr = new int[size];
	for (unsigned int i = 0; i < size; ++i) cin >> arr[i];
	cin.close();
	cout << "Max Different in array:" << maxDiff_1(arr, size) << "\n";
	cout << "Max Different in array:" << maxDiff_2(arr, size) << "\n";
	cout << "Max Different in array:" << maxDiff_3(arr, size) << "\n";

	delete[] arr;
	return 0;
}

static inline int maxDiff_1(int* start, int* end, int& max, int& min) {
	if (start == end) {
		max = min = *start;
		return 0x80000000;
	}
	int* middle = start + ((end - start) / 2);
	int leftmax = 0, leftmin = 0;
	int leftdiff = maxDiff_1(start, middle, leftmax, leftmin);
	int rightmax = 0, rightmin = 0;
	int rightdiff = maxDiff_1(middle + 1, end, rightmax, rightmin);
	int crossDiff = leftmax - rightmin;
	max = (rightmax > leftmax) ? rightmax : leftmax;
	min = (rightmin > leftmin) ? leftmin : rightmin;

	int maxdiff = (crossDiff > leftdiff) ? crossDiff : leftdiff;
	maxdiff = (maxdiff > rightdiff) ? maxdiff : rightdiff;
	return maxdiff;
}

int maxDiff_1(int arr[], const int length) {
	if (NULL == arr || length < 2) return 0;
	int min, max = 0;
	return maxDiff_1(arr, arr + length - 1, max, min);
}
/**
 *
 接下来再介绍一种比较巧妙的解法。如果输入一个长度为n的数组numbers，我们先构建一个长度
 *
 为n-1的辅助数组diff，并且diff[i]等于numbers[i]-numbers[i+1]（0<=i<n-1）。如果我
 * 们从数组diff中的第i个数字一直累加到第j个数字（j > i），也就是
 diff[i] + diff[i+1] + … + diff[j]
 =
 (numbers[i]-numbers[i+1])+(numbers[i+1]-numbers[i+2])+...+(numbers[j]–numbers[j+1])
 = numbers[i] – numbers[j + 1]。
 *
 */
int maxDiff_2(int arr[], const int length) {
	if (NULL == arr || length < 2) return 0;
	int* diff = new int[length - 1];
	//
	for (unsigned int i = 1; i < length; i++) {
		diff[i - 1] = arr[i - 1] - arr[i];
	}
	// get max sequense addition result
	int currentSum = 0;
	int greatestSum = 0x80000000;
	for (unsigned int i = 0; i < length - 1; i++) {
		if (currentSum >= 0)
			currentSum += diff[i];
		else
			currentSum = diff[i];
		if (currentSum > greatestSum) greatestSum = currentSum;
	}
	delete[] diff;
	return greatestSum;
}
/**
 * 既然我们可以把求最大的数对之差转换成求子数组的最大和，而子数组的最大和可以通过动态规划求解，
 * 那我们是不是可以通过动态规划直接求解呢？下面我们试着用动态规划法直接求数对之差的最大值。
 * 我们定义diff[i]是以数组中第i个数字为减数的所有数对之差的最大值。也就是说对于任意h（h
 * < i），
 * diff[i]≥number[h]-number[i]。diff[i]（0≤i<n）的最大值就是整个数组最大的数对之差。
 * 假设我们已经求得了diff[i]，我们该怎么求得diff[i+1]呢？对于diff[i]，肯定存在一个h（h
 * < i），
 * 满足number[h]减去number[i]之差是最大的，也就是number[h]应该是number[i]之前的所有数字的最大值。
 * 当我们求diff[i+1]的时候，我们需要找到第i+1个数字之前的最大值。第i+1个数字之前的最大值有两种可能：
 * 这个最大值可能是第i个数字之前的最大值，也有可能这个最大值就是第i个数字。第i+1个数字之前的最大值
 * 肯定是这两者的较大者。我们只要拿第i+1个数字之前的最大值减去number[i+1]，就得到了diff[i+1]
 */
int maxDiff_3(int arr[],const int length)
{
	if(NULL==arr||length<2)return 0;
	int max=arr[0];
	int maxDiff = max-arr[1];
	int currentDiff=0;
	for(int i=2;i<length;i++)
	{
		if(arr[i-1]>max)
			max=arr[i-1];
		currentDiff=max-arr[i];
		if(currentDiff>maxDiff)
			maxDiff=currentDiff;
	}
	return maxDiff;
}