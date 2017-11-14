#pragma once

namespace LiteSTL
{

	struct InputIteratorTag{};
	struct OutputIteratorTag{};
	struct ForwardIteratorTag : public InputIteratorTag {};
	struct BidirectionalIteratorTag : public ForwardIteratorTag {};
	struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};

	/*���������*/
	template<typename T, typename Distance>
	struct InputIterator
	{
		using IteratorCategory	= InputIteratorTag;
		using ValueType			= T;
		using DifferenceType	= Distance;
		using Pointer			= T*;
		using Reference			= T&;
	};

	/*���������*/
	struct OutputIterator
	{
		using IteratorCategory	= OutputIteratorTag;
		using ValueType			= void;
		using DifferenceType	= void;
		using Pointer			= void;
		using Reference			= void;
	};

	/*���������*/
	template<typename T, typename Distance>
	struct ForwardIterator
	{
		using IteratorCategory	= ForwardIteratorTag;
		using ValueType			= T;
		using DifferenceType	= Distance;
		using Pointer			= T*;
		using Reference			= T&;
	};

	/*˫�������*/
	template<typename T, typename Distance>
	struct BidirectionalIterator
	{
		using IteratorCategory	= BidirectionalIteratorTag;
		using ValueType			= T;
		using DifferenceType	= Distance;
		using Pointer			= T*;
		using Reference			= T&;
	};

	/*������ʵ�����*/
	template<typename T, typename Distance>
	struct RandomAccessIterator
	{
		using IteratorCategory	= RandomAccessIteratorTag;
		using ValueType			= T;
		using DifferenceType	= Distance;
		using Pointer			= T*;
		using Reference			= T&;
	};

	template<typename Category, typename T, typename Distance = ptrdiff_t>
	struct Iterator
	{
		using IteratorCategory	= Category;
		using ValueType			= T;
		using DifferenceType	= Distance;
		using Pointer			= T*;
		using Refference		= T&;
	};

	template<typename Iterator>
	struct IteratorTraits
	{
		using IteratorCategory	= typename Iterator::IteratorCategory;
		using ValueType			= typename Iterator::ValueType;
		using DifferenceType	= typename Iterator::DifferenceType;
		using Pointer			= typename Iterator::Pointer;
		using Reference			= typename Iterator::Reference;
	};
}