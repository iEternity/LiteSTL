#pragma once
#include "TypeTraits.h"
#include "Construct.h"

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
}