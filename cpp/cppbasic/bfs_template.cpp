#include <iostream>

#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
* @brief 反向生成路径.
* @param[in] father 树
* @param[in] target 目标节点
* @return 从起点到 target 的路径
*/
template<typename state_t>
vector<state_t> gen_path(const unordered_map<state_t, state_t> &father, const state_t &target) 
{
	vector<state_t> path;
	path.push_back(target);
	state_t cur = target;
	while (father.find(cur) != father.end()) 
	{
		cur = father.at(cur);
		path.push_back(cur);
	}
	reverse(path.begin(), path.end());
	return path;
}
/**
* @brief 广搜.
* @param[in] state_t 状态，如整数，字符串，一维数组等
* @param[in] start 起点
* @param[in] state_is_target 判断状态是否是目标的函数
* @param[in] state_extend 状态扩展函数
* @return 从起点到目标状态的一条最短路径
*/
template<typename state_t>
vector<state_t> bfs(state_t &start, bool (*state_is_target)(const state_t&),
vector<state_t>(*state_extend)(const state_t&,unordered_set<string> &visited)) 
{
	queue<state_t> next, current; // 当前层，下一层
	unordered_set<state_t> visited; // 判重
	unordered_map<state_t, state_t> father;
	int level = 0; // 层次
	bool found = false;
	state_t target;
	current.push(start);

	while (!current.empty() && !found) 
	{
		++level;
		while (!current.empty() && !found) 
		{
			const state_t state = current.front();
			current.pop();
			vector<state_t> new_states = state_extend(state, visited);
			for (auto iter = new_states.cbegin(); 
						iter != new_states.cend() && ! found; ++iter) 
			{
				const state_t new_state(*iter);
				if (state_is_target(new_state)) 
				{
					found = true; //找到了
					target = new_state;
					father[new_state] = state;
					break;
				}
				next.push(new_state);
				// visited.insert(new_state); 必须放到 state_extend() 里
				father[new_state] = state;
			}
		}
		swap(next, current); //!!! 交换两个队列
	}
	if (found) {
		return gen_path(father, target);
	//return level + 1;
	} else {
		return vector<state_t>();
	//return 0;
	}
}