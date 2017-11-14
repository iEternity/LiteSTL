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

template<typename T, typename Allocator>
Vector<T, Allocator>::Vector(size_t n, const ValueType& value)
{
	allocateAndFillN(n, value);
}

template<typename T, typename Allocator>
template<typename InputIterator>
Vector<T, Allocator>::Vector(InputIterator first, InputIterator last)
{
	vectorAux(first, last, typename IsIntegral<InputIterator>::Type());
}

template<typename T, typename Allocator>
Vector<T, Allocator>::Vector(const Vector& v)
{
	allocateAndCopy(v.begin_, v.end_);
}

template<typename T, typename Allocator>
Vector<T, Allocator>::Vector(Vector&& v)
{
	*this = std::move(v);
}

template<typename T, typename Allocator>
Vector<T, Allocator>& Vector<T, Allocator>::operator = (const Vector& v)
{
	if (this != &v)
	{
		allocateAndCopy(v.begin_, v.end_);
	}

	return *this;
}

template<typename T, typename Allocator>
Vector<T, Allocator>& Vector<T, Allocator>::operator = (Vector&& v)
{
	if (this != &v)
	{
		begin_ = v.begin_;
		end_ = v.end_;
		endOfStorage_ = v.endOfStorage_;

		v.begin_ = nullptr;
		v.end_ = nullptr;
		v.endOfStorage_ = nullptr;
	}

	return *this;
}

template<typename T, typename Allocator>
Vector<T, Allocator>::~Vector()
{
	destroyAndDeallocateAll();
}

template<typename T, typename Allocator>
bool Vector<T, Allocator>::operator == (const Vector& v) const
{
	if (size() != v.size()) return false;

	auto p1 = begin_;
	auto p2 = v.begin_;

	for (; p1 != end_ && p2 != v.end_; p1++, p2++)
	{
		if (*p1 != *p2) return false;
	}

	return true;
}

template<typename T, typename Allocator>
bool Vector<T, Allocator>::operator != (const Vector& v) const
{
	return !(*this == v);
}

template<typename T, typename Allocator>
void Vector<T, Allocator>::allocateAndFillN(size_t n, const ValueType& value)
{
	begin_	= Allocator::allocate(n);
	end_	= uninitializedFillN(begin_, n, value);
	endOfStorage_ = end_;
}

template<typename T, typename Allocator>
template<typename InputIterator>
void Vector<T, Allocator>::allocateAndCopy(InputIterator first, InputIterator last)
{
	begin_	= Allocator::allocate(last - first);
	end_	= uninitializedCopy(first, last, begin_);
	endOfStorage_ = end_;
}

template<typename T, typename Allocator>
void Vector<T, Allocator>::destroyAndDeallocateAll()
{

}

template<typename T, typename Allocator>
template<typename InputIterator>
void Vector<T, Allocator>::vectorAux(InputIterator first, InputIterator last, FalseType)
{
	allocateAndCopy(first, last);
}

template<typename T, typename Allocator>
template<typename Integer>
void Vector<T, Allocator>::vectorAux(Integer n, const ValueType& value, TrueType)
{
	allocateAndFillN(n, value);
}



}

