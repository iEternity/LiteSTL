#pragma once

#include "Allocator.h"
#include "TypeTraits.h"
#include <cstddef>

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
	using DataAllocator			= Allocator;

public:
	/*���졢��ֵ�����ơ�����*/
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

	Vector(const Vector& v);
	Vector(Vector&& v);

	Vector& operator = (const Vector& v);
	Vector& operator = (Vector&& v);

	~Vector();

	/*�Ƚϲ���*/
	bool operator == (const Vector& v) const;
	bool operator != (const Vector& v) const;

	/*������*/
	Iterator		begin()				{ return begin_; }
	ConstIterator	begin() const		{ return begin_; }
	ConstIterator	cbegin() const		{ return begin_; }
	Iterator		end()				{ return end_; }
	ConstIterator	end() const			{ return end_; }
	ConstIterator	cend() const		{ return end_; }

	/*�������*/
	DifferenceType	size() const		{ return end_ - begin_; }
	DifferenceType	capacity() const	{ return endOfStorage_ - begin_; }

	/*����Ԫ�����*/

	/*�޸�����*/

	/*�ռ�������*/

private:
	/*�ڴ���估��ʼ��*/
	void allocateAndFillN(size_t n, const ValueType& value);
	
	template<typename InputIterator>
	void allocateAndCopy(InputIterator first, InputIterator last);

	/*�ͷ��ڴ漰����*/
	void destroyAndDeallocateAll();

	/*��������*/
	template<typename InputIterator>
	void vectorAux(InputIterator first, InputIterator last, FalseType);

	template<typename Integer>
	void vectorAux(Integer n, const ValueType& value, TrueType);

	

private:
	Iterator begin_;
	Iterator end_;
	Iterator endOfStorage_;
};

}

#include "../Detail/Vector.impl.h"