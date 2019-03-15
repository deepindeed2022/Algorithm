template<class T>
class Vec
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;
public:
	Vec(){create();}
	explicit Vec(size_type n,const T& val=T())
	{
		create(n,val);
	}
	T& operator[](size_type i)const {return data[i];}
	const T&operator[](size_type i)const {return data[i];}
	~Vec();
private:
	iterator data;
	iterator limit;

};