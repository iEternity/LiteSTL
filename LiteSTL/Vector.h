#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Allocator.h"

namespace LiteSTL
{
	
template<class T, class Alloc = allocator<T>>
class vector
{
public:
	vector()
		:start_(0), finish_(0), endOfStorage_(0){}
	vector(const size_type n, const value_type& value);

	iterator begin(){ return start_; }
	iterator end(){ return finish_; }

private:
	void allocateAndFillN(const size_type n, const value_type& value);

private:
	typedef Alloc dataAllocator;
	T* start_;
	T* finish_;
	T* endOfStorage_;

public:
	typedef T					value_type;
	typedef T*					iterator;
	typedef const T*			const_iterator;
	typedef size_t				size_type;
};

}

#include"../Detail/Vector.impl.h"
#endif