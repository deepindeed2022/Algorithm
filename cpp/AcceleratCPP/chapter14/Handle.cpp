#include "Handle.h"
#include <stdexcept>
template<class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
	if(&rhs != this)
	{
		delete p;
		p=rhs.p ? rhs.p->clone() :0;
	}
	return *this;
}
template<class T>
T& Handle<T>::operator*(const Handle& rhs)
{
	if(p)
		return *p;
	throw std::runtie_error("unbound Handle");
}
template<class T>
T* Handle<T>::operator->(const Handle& rhs)
{
	if(p)
		return p;
	throw std::runtie_error("unbound Handle");
}



