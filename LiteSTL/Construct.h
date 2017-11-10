#pragma once

namespace LiteSTL
{

template<typename T1, typename T2>
inline void construct(T1* ptr, const T2& value)
{
	new (ptr) T2(value);
}

}