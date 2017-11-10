#pragma once

#include "Allocator.h"

namespace LiteSTL
{
	
template<class T, class Allocator = Allocator<T>>
class Vector
{
public:
	using ValueType = T;
	using Iterator = T*;
	using ConstIterator = const T*;

public:
	Vector():
		begin_(0), 
		end_(0), 
		endOfStorage_(0)
	{
	}
	Vector(const size_t n, const ValueType& value);

	Iterator begin()	{ return begin_; }
	Iterator end()		{ return end_; }

private:
	void allocateAndFillN(const size_t n, const ValueType& value);

private:
	Iterator begin_;
	Iterator end_;
	Iterator endOfStorage_;
};

}

#include "../Detail/Vector.impl.h"