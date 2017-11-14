#pragma once
#include "Iterator.h"

namespace LiteSTL
{

template<typename Iterator>
class ReverseIterator
{
public:
	using IteratorCategory	= typename IteratorTraits<Iterator>::IteratorCategory;
	using ValueType			= typename IteratorTraits<Iterator>::ValueType;
	using DifferenceType	= typename IteratorTraits<Iterator>::DifferenceType;
	using Pointer			= typename IteratorTraits<Iterator>::Pointer;
	using ConstPointer		= const Pointer;
	using Reference			= typename IteratorTraits<Iterator>::Reference;
	using ConstReference	= const Reference;

public:
	ReverseIterator() : base(nullptr), cur_(nullptr){};
	explicit ReverseIterator(const Iterator& it) : base(nullptr), cur_(it - 1){};
	
	template<typename Iter>
	ReverseIterator(const ReverseIterator_t<Iter>& it)
	{
		base_ = static_cast<Iterator>(it.base_);
		cur_ = base_ - 1;
	}

	Iterator			base() const					{ return base_; }
	Reference			operator*()						{ return *cur_; }
	ConstReference		operator*() const				{ return *cur_; }
	Pointer				operator->()					{ return &(operator*()); }
	ConstPointer		operator->() const				{ return &(operator*()); }
	ReverseIterator&	operator++()					{ --base_; --cur_; return *this; }
	ReverseIterator		operator++(int)					{ auto tmp = *this; ++(*this); return tmp; }
	ReverseIterator&	operator--()					{ ++base_; ++cur_; return *this; }
	ReverseIterator		operator--(int)					{ auto tmp = *this; --(*this); return tmp; }
	Reference			operator[](DifferenceType n)	{ return *(base_ - n - 1); }
	ReverseIterator		operator+(DifferenceType n)	const;
	ReverseIterator&	operator+=(DifferenceType n);
	ReverseIterator		operator-(DifferenceType n) const;
	ReverseIterator		operator-=(DifferenceType n);

	/*外部友元函数*/
	template<typename Iterator>
	friend bool operator==(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) const;

	template<typename Iterator>
	friend bool operator!=(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator>& rhs) const;

	template<typename Iterator>
	friend bool operator<(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) const;

	template<typename Iterator>
	friend bool operator<=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) const;

	template<typename Iterator>
	friend bool operator>(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) const;

	template<typename Iterator>
	friend bool operator>=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) const;

	template<typename Iterator>
	friend ReverseIterator operator+(typename ReverseIterator<Iterator>::DifferenceType n, const ReverseIterator<Iterator>& it);

	template<typename Iterator>
	friend typename ReverseIterator<Iterator>::DifferenceType operator-(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs);

private:
	Iterator advanceNStep(Iterator it, DifferenceType n, bool rightward, RandomAccessIteratorTag)
	{
		if (rightward)
		{
			return it + n;
		}
		else
		{
			return it - n;
		}
	}

	Iterator advanceNStep(Iterator it, DifferenceType n, bool rightward, BidirectionalIteratorTag)
	{
		DifferenceType absN = n >= 0 ? n : -n;
		if ((n >= 0 && rightward) || (n < 0 && !rightward))	//forward
		{
			return it + n;
		}
		else //reverse
		{
			return it - n;
		}
	}

private:
	Iterator base_;
	Iterator cur_;
};	//end of ReverseIterator

template<typename Iterator>
ReverseIterator<Iterator> ReverseIterator<Iterator>::operator+(DifferenceType i)
{
	base_ += i;
	cur_ += i;
	return *this;
}

}