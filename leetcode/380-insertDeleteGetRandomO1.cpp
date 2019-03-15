#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::string;
using std::cout;
using std::cin;
using std::endl;
#include <cassert>
#include <cstdlib>
class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        nums.emplace_back(val);
        m[val] = nums.size() -1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

int main(int argc, char const *argv[])
{
    RandomizedSet obj;
    bool param_1 = obj.insert(5);
    bool param_2 = obj.insert(4);
    obj.insert(3);
    assert(param_1);
    assert(param_2);
    int param_4 = obj.getRandom();
    std::cout << param_4 << std::endl;
    bool param_3 = obj.remove(4);
    assert(param_3);
    return 0;
}