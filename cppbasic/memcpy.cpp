#include <iostream>
using std::cout;
using std::endl;
/*
 memcpy说明：
 其中要考虑的是
  1. 判断输入人指针是否为空 
  2. 内存是否有重叠
  3. 不同架构上是否可以考虑一次拷贝多个进行copy加速，
     如在32bit机器上可以每次cpy 4个bytes， 64bit的机器上可以考虑一次cpy8个字节
  4. check memcpy 和memmove两个函数的实现

 */
void* memcpy(void* src, void* dst, size_t len)
{
	//判断输入人指针是否为空
	if(src == NULL||dst == NULL) return NULL;
	void * ret = dst;
	//内存是否有重叠
	if(dst <= src || (char*)dst >= (char*)src + len)
	{
		for(size_t i= 0; i < len - 4; len -= 4)
		{
			*(int*)dst  = *(int*)src;
			dst  = (int*)dst + 1;
			src  = (int*)src + 1;
		}
		while(len--) {
			*(char*)dst  = *(char*)src;
			dst  = (char*)dst + 1;
			src  = (char*)src + 1;
		};	
	}
	else
	{
		src = (char*)src + len -1;
		dst = (char*)dst + len -1;
		for(size_t i= 0; i < len - 4; len -= 4)
		{
			*(int*)dst  = *(int*)src;
			dst  = (int*)dst - 1;
			src  = (int*)src - 1;
		}
		while(len--) 
		{
			*(char*)dst= *(char*)src;
			dst  = (char*)dst - 1;
			src  = (char*)src - 1;
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	char a[] = {'a', 'b','c','d','e','f','g','h','i','j','k'};
	char *b = new char[8];
	b = (char*)memcpy(a, b, 8);
	for(int i = 0; i < 8; ++i)
	{
		std::cout << b[i]<< " ";
	}
	return 0;
}