

/**
* dfs 模板.
* @param[in] input 输入数据指针
* @param[inout] cur or gap 标记当前位置或距离目标的距离
* @param[out] path 当前路径，也是中间结果
* @param[out] result 存放最终结果
* @return 路径长度，如果是求路径本身，则不需要返回长度
*/
template <typename T>
void dfs(T *input, T *path, int cur or gap, T *result) 
{
	// 数据检查
	if (数据非法) return 0; // 终止条件

	if (cur == input.size( or gap == 0)) 
	{ 
		// 收敛条件
		将 path 放入 result
	}
	if (可以剪枝) 
		return;
	
	// 执行所有可能的扩展动作
	for(...) 
	{ 
		执行动作，修改 path
		dfs(input, step + 1 or gap--, result);
		恢复 path
	}
}