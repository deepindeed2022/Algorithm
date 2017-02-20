#include <iostream>
#include <vector>
#include <algorithm>
using std::max;
using namespace std;
struct Interval
{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int _start, int _end):start(_start),end(_end){}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	if(intervals.size() == 0)
	{
		intervals.push_back(newInterval);
	    return intervals;
	    
	}
	Interval mergeInterval;
	mergeInterval.start = newInterval.start;
	int i = 0;
	
	while(i < intervals.size() && intervals[i].end < newInterval.start)++i;

	if(i < intervals.size() && intervals[i].start <= newInterval.start)
	{
		mergeInterval.start = intervals[i].start;
	}
	while(i < intervals.size() && intervals[i].end < newInterval.end)
		intervals.erase(intervals.begin() + i);
	
	if(i < intervals.size())
	{
		if(intervals[i].start <= newInterval.end)
		{
			
			mergeInterval.end = max(newInterval.end, intervals[i].end) ;
			intervals.erase(intervals.begin()+i);
			intervals.insert(intervals.begin() + i, mergeInterval);
		}
		else
		{
			mergeInterval.end = newInterval.end;
			intervals.insert(intervals.begin() + i, mergeInterval);
		}
	}
	else
	{
	    mergeInterval.end = newInterval.end;
	    intervals.push_back(mergeInterval);
	}
	return intervals;
}
