#pragma once

#include "Allocator.h"

namespace LiteSTL
{
	
template<class T, class Allocator = Allocator<T>>
class Vector
{
public:
	using ValueType				= T;
	using Iterator				= T*;
	using ConstIterator			= const T*;
	using Pointer				= T*;
	using Reference				= T&;
	using ConstReference		= const T&;
	using DifferenceType		= ptrdiff_t;

public:
	Vector():
		begin_(0), 
		end_(0), 
		endOfStorage_(0)
	{
	}
	explicit Vector(size_t n);
	Vector(size_t n, const ValueType& value);
	template<typename InputIterator>
	Vector(InputIterator first, InputIterator last);

	Iterator begin()	{ return begin_; }
	Iterator end()		{ return end_; }

private:
	void allocateAndFillN(size_t n, const ValueType& value);

private:
	Iterator begin_;
	Iterator end_;
	Iterator endOfStorage_;
};

}

#include "../Detail/Vector.impl.h"