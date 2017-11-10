#pragma once
#include "../Vector.h"
#include "../UninitializedFunctions.h"

namespace LiteSTL
{

template<typename T, typename Allocator>
Vector<T, Allocator>::Vector(size_t n)
{
	allocateAndFillN(n, ValueType());
}

template<class T, class Allocator>
Vector<T, Allocator>::Vector(const size_t n, const ValueType& value)
{
	allocateAndFillN(n, value);
}

template<class T, class Allocator>
void Vector<T, Allocator>::allocateAndFillN(const size_t n, const ValueType& value)
{
	begin_ = Allocator::allocate(n);
	end_ = endOfStorage_ = uninitializedFillN(begin_, n, value);
}

}

