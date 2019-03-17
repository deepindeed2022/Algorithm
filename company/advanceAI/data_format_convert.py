#!/usr/bin/python 
# -*- coding: utf-8 -*- 

"""
【第二题】数据存取
我们的程序运行过程中用到了一个数组a，数组元素是一个map/dict。
数组元素的“键”和“值”都是字符串类型。在不同的语言中，对应的类型是：
PHP的array, Java的HashMap, C++的std::map, Objective-C的NSDictionary, Swift的Dictionary, Python的dict, JavaScript的object, 等等
示例：
a[0]["key1"]="value1"
a[0]["key2"]="value2"
a[1]["keyA"]="valueA"

...
为了方便保存和加载，我们使用了一个基于文本的存储结构，数组元素每行一个：
text="key1=value1;key2=value2\nkeyA=valueA\n..."

要求：请实现一个“保存”函数、一个“加载”函数。
text=store(a);  //把数组保存到一个文本字符串中
a=load(text); //把文本字符串中的内容读取为数组
必须严格按照上述的“每行一个、key=value”的格式保存。
"""

def store(arr):
	"""format a dict array to plain text
	"""
	text = ""
	for line in arr:
		text += ";".join(map(lambda (k, v): "{}={}".format(k, v), line.iteritems())) + "\n"
	return text

def load(text):
	"""load persistance text into a dict array"""
	lines = text.split()
	arr = []
	for line in lines:
		arr.append(reduce(lambda x, y: dict(x.items(), **y), \
			map(lambda x: {x.split("=")[0] : x.split("=")[1]}, line.split(";"))))
		# var = dict()
		# for kv in line.split(";"):
		# 	var[kv.split("=")[0]] = kv.split("=")[1]
		# arr.append(var)
	return arr

if __name__ == '__main__':	
	text="key1=value1;key2=value2\nkeyA=valueA;keyB=valueB;keyC=valueC\nkeyxx=sdsdfs\n"
	arr = load(text)
	our_text = store(arr)
