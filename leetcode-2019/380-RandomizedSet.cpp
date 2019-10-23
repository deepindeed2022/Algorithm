#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashMap.find(val) != hashMap.end()) {
            return false;
        }
        vec.push_back(val);
        hashMap[val] = vec.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashMap.find(val) == hashMap.end()) {
            return false;
        }
        int index = hashMap.find(val)->second;
        if(index == vec.size() - 1) {
            vec.pop_back();
            hashMap.erase(val);
        } else {
            hashMap[vec[vec.size() - 1]] = index;
            std::swap(vec[index], vec[vec.size() - 1]);
            vec.pop_back();
            hashMap.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(vec.size() <= 0) {
            return -1;
        }
        int index = rand() % vec.size();
        return vec[index];
    }
private:
    std::unordered_map<int, int> hashMap;
    std::vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(int argc, char const *argv[])
{
    // 初始化一个空的集合。
    RandomizedSet randomSet;

    // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    randomSet.insert(1);
    // 返回 false ，表示集合中不存在 2 。
    randomSet.remove(2);

    // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    randomSet.insert(2);

    // getRandom 应随机返回 1 或 2 。
    randomSet.getRandom();

    // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    randomSet.remove(1);

    // 2 已在集合中，所以返回 false 。
    randomSet.insert(2);

    // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
    randomSet.getRandom();
    return 0;
}