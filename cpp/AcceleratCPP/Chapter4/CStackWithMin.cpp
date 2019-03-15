/**
 * 讨论：如果思路正确，编写上述代码不是一件很难的事情。但如果能注意一些细节无疑能在面试中加分。
 比如我在上面的代码中做了如下的工作：
· 用模板类实现。如果别人的元素类型只是int类型，模板将能给面试官带来好印象；
· 两个版本的top函数。在很多类中，都需要提供const和非const版本的成员访问函数；
· min函数中assert。把代码写的尽量安全是每个软件公司对程序员的要求；
· 添加一些注释。注释既能提高代码的可读性，又能增加代码量，何乐而不为？
总之，在面试时如果时间允许，尽量把代码写的漂亮一些。说不定代码中的几个小亮点
就能让自己轻松拿到心仪的Offer。
 */
#include <deque>
#include <assert.h>
#include <iostream>
using namespace std;
template <typename T> class CStackWithMin
{
public:
      CStackWithMin(void) {}
      virtual ~CStackWithMin(void) {}

      T& top(void);
      const T& top(void) const;

      void push(const T& value);
      void pop(void);

      const T& min(void) const;

private:
     deque<T> m_data;               // the elements of stack
     deque<size_t> m_minIndex;      // the indices of minimum elements
};
// get the last element of mutable stack
template <typename T> T& CStackWithMin<T>::top()
{
      return m_data.back();
}
// get the last element of non-mutable stack
template <typename T> const T& CStackWithMin<T>::top() const
{
      return m_data.back();
}
// insert an elment at the end of stack
template <typename T> void CStackWithMin<T>::push(const T& value)
{
      // append the data into the end of m_data
      m_data.push_back(value);
      // set the index of minimum elment in m_data at the end of m_minIndex
      if(m_minIndex.size() == 0)
            m_minIndex.push_back(0);
      else
      {
            if(value < m_data[m_minIndex.back()])
                  m_minIndex.push_back(m_data.size() - 1);
            else
                  m_minIndex.push_back(m_minIndex.back());
      }
}
// erease the element at the end of stack
template <typename T> void CStackWithMin<T>::pop()
{
      // pop m_data
      m_data.pop_back();
      // pop m_minIndex
      m_minIndex.pop_back();
}
// get the minimum element of stack
template <typename T> const T& CStackWithMin<T>::min() const
{
      assert(m_data.size() > 0);
      assert(m_minIndex.size() > 0);
      return m_data[m_minIndex.back()];
}
int main()
{
	CStackWithMin<int>*s=new CStackWithMin<int>();
	s->push(12);
	s->push(13);
	s->push(23);
	std::cout<<s->min()<<std::endl;
	return 1;
}
