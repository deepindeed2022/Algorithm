#!/usr/bin/python 
# -*- coding: utf-8 -*- 

"""
【第一题】JSON格式转换
在某个特定应用场景中，我们有一个从JSON获取的内容，比如：
m = { "a": 1, "b": { "c": 2, "d": [3,4] } }
现在需要把这个层级的结构做展开，只保留一层key/value结构。对于上述输入，需要得到的结构是：
o = {"a": 1, "b.c": 2, "b.d": [3,4] }
也就是说，原来需要通过 m["b"]["c"] 访问的值，在展开后可以通过 o["b.c"] 访问。
请实现这个“层级结构展开”的代码。
输入：任意JSON（或者map/dict）
输出：展开后的JSON（或者map/dict）
"""

def json_format(json):
	"""format a json input to a dict which value not dict"""
	assert isinstance(json, dict)
	out = dict()
	path = []
	def json2dict(json):
		for k, v in json.iteritems():
			if isinstance(v, dict):
				path.append(k)
				json2dict(v)
				path.pop()
			else:
				path.append(k)
				out[".".join(path)] = v
				path.pop()

	json2dict(json)
	return out


if __name__ == '__main__':	
	m = dict({ "a": 1, "b": { "c": 2, "d": [3,4] } })
	print json_format(m)