#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using std::max;
using std::min;
using std::vector;
using std::cout;
using std::equal;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) { }
	Interval(int s, int e) : start(s), end(e) { }

};
bool interval_eq(const Interval& first, const Interval& second)
{
	return first.start == second.start 
			&& first.end == second.end;
}
// Insert a element into a Interval vector
// There are 5 possiable conditions.
// 1.
//           [___]
//    [___]
// 2.
//           [___]
//        [___]
// 3.
//           [_______]
//             [___]
// 4.
//           [___]
//             [___]
// 5.
//           [___]
//                 [___]
// the 2,3,4 may use max and min to get the interval's start and end
// the first and last case, we will handle specially.
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	std::vector<Interval>::iterator it = intervals.begin();
	while(it != intervals.end())
	{
		if(newInterval.end < it->start)
		{
			intervals.insert(it, newInterval);
			return intervals;
		}
		else if(newInterval.start > it->end)
		{
			it++;
			continue;
		}else 
		{
			newInterval.start = min(newInterval.start, it->start);
			newInterval.end = max(newInterval.end, it->end);
			it = intervals.erase(it);
		}
	}
	intervals.insert(intervals.end(), newInterval);
	return intervals;
}
vector<Interval> merge(vector<Interval> &intervals)
{
	vector<Interval> result;
	for (int i = 0; i < intervals.size(); i++) {
		insert(result, intervals[i]);
	}
	return result;
}
void test_insert()
{
	vector<Interval> vec;
	vec.push_back(Interval(1,5));
	Interval newInterval(2,3);
	vector<Interval> result = insert(vec, newInterval);
	assert(result[0].start == 1 && result[0].end == 5);
	// for(int i = 0; i < result.size(); ++i)
	// {
	// 	std::cout << result[i].start << " " << result[i].end << std::endl;
	// }
}
void test_merge()
{
	vector<Interval> vec;
	vec.push_back(Interval(1,3));
	vec.push_back(Interval(2,6));
	vec.push_back(Interval(8,10));
	vec.push_back(Interval(15,18));
	std::vector<Interval> result = merge(vec);
	std::vector<Interval> expect_result;
	expect_result.push_back(Interval(1, 6));
	expect_result.push_back(Interval(8, 10));
	expect_result.push_back(Interval(15, 18));
	assert(std::equal(result.begin(), result.end(),expect_result.begin(), interval_eq));
}
int main(int argc, char const *argv[])
{
	test_insert();
	test_merge();
	return 0;
}