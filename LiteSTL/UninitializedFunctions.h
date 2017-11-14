#pragma once
#include "TypeTraits.h"
#include "Construct.h"
#include "Iterator.h"

namespace LiteSTL
{
	/*uninitializedFillN*/
	template<typename ForwardIterator, typename Size, typename T>
	ForwardIterator _uninitializedFillN(ForwardIterator first, Size n, const T& value, TrueType)
	{
		for (; n > 0; n--, first++)
		{
			*first = value;
		}
		return first;
	}
	template <typename ForwardIterator, typename Size, typename T>
	ForwardIterator _uninitializedFillN(ForwardIterator first, Size n, const T& value, FalseType)
	{
		for (; n > 0; n--, first++)
		{
			construct(first, value);
		}
		return first;
	}

	template<typename ForwardIterator, typename Size, typename T>
	inline ForwardIterator uninitializedFillN(ForwardIterator first, Size n, const T& value)
	{
		using IsPODType = typename TypeTraits<T>::IsPODType;
		return _uninitializedFillN(first, n, value, IsPODType());
	}

	/*uninitializedFill*/

	/*uninitializedCopy*/
	template<typename InputIterator, typename ForwardIterator>
	ForwardIterator _uninitializedCopy(InputIterator first, InputIterator last, ForwardIterator result, TrueType)
	{
		memcpy(result, first, (last - first) * sizeof(*first));
		return result + (last - first);
	}

	template<typename InputIterator, typename ForwardIterator>
	ForwardIterator _uninitializedCopy(InputIterator first, InputIterator last, ForwardIterator result, FalseType)
	{
		for (; first != last; first++, result++)
		{
			construct(result, *first);
		}
		return result;
	}

	template<typename InputIterator, typename ForwardIterator>
	inline ForwardIterator uninitializedCopy(InputIterator first, InputIterator last, ForwardIterator result)
	{
		using IsPODType = typename TypeTraits<IteratorTraits<InputIterator>::ValueType>::IsPODType;
		_uninitializedCopy(first, last, result, IsPODType);
	}

}