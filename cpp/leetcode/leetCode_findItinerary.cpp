#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using std::vector;
using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        map< string, multiset<string> > myGraph;
        int i, n = tickets.size();
        string first, second;
        for(i=0; i<n; i++)
        {
            first  = tickets[i].first;
            second = tickets[i].second;
            myGraph[first].insert(second);
        }

        vector<string> marching;
        vector<string> itinerary;
        marching.push_back("JFK");

        while(marching.size()>0)
        {
            string from = marching.back();
            if(myGraph.count(from)>0 && myGraph[from].size()>0)
            {
                multiset<string>& to = myGraph[from];
                marching.push_back(*to.begin());
                to.erase(to.begin());
            }
            else
            {
                itinerary.push_back(from);
                marching.pop_back();
            }
        }

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
