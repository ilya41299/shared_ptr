#include <iostream>
#include <algorithm>
#include <cassert>

template <typename T>
class shared_ptr {
private:
	size_t *count;
	T * ptr_;
public:
	shared_ptr(T * ptr = nullptr); 
	~shared_ptr();
	shared_ptr(shared_ptr const & other);
	shared_ptr & operator =(shared_ptr const & other);
	void swap(shared_ptr & shared);
	void reset(T * ptr = nullptr);
	T & operator*() const;
	T * operator->() const;
	T * get() const;
};

template <typename T>
shared_ptr<T>::shared_ptr(T * ptr) 
{
	ptr_ = ptr;
	if (ptr_) count = new size_t (1); 
	else count = nullptr;
}

template <typename T>
shared_ptr<T>::~shared_ptr()
{
	if (count && --*count==0)
	{
		delete ptr_;
		delete count;
	}
}

template <typename T>
shared_ptr<T>::shared_ptr(shared_ptr const & other)
{
	ptr_ = other.ptr_;
	if (other.count) ++*count;
	else count = nullptr;
}

template <typename T>
shared_ptr<T> & shared_ptr<T>::operator= (shared_ptr const & other) 
{
	if (&other != this) 
	{
		shared_ptr(other).swap(*this);
	}
	return *this;
}

template <typename T>
void shared_ptr<T>::swap(shared_ptr & shared)
{
	std::swap(shared.ptr_, ptr_);
	std::swap(shared.counter_, counter_);
}

template <typename T>
void shared_ptr<T>::reset(T * ptr)
{
	shared_ptr(ptr).swap(*this);
}

template <typename T>
T & shared_ptr<T>::operator*() const
{
	return *ptr_;
}

template <typename T>
T * shared_ptr<T>::operator->() const
{
	return ptr_;
}

template <typename T>
T * shared_ptr<T>::get() const
{
	return ptr_;
}
