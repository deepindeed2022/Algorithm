#ifndef HANDLE
#define HANDLE
template <class T> 
class Handle{
	public:
		Handle():p(0){}
		Handle(const Handle& s):p(0)
		{
			if(s.p) 
				p =s.p->clone();
		}
		Handle& operator=(const Handle&);
		~Handle()
		{
			delete p;
		}
		Handle(T* t):p(t)
		{

		}
		operator bool()const 
		{
			return p;
		}
		T& operator*()const;
		T* operator->()const;
	private:
		T* p;
};
#endif