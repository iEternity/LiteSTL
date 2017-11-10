#pragma once
#include "Alloc.h"

namespace LiteSTL
{

template<class T>
class Allocator
{
public:
	static T* allocate();
	static T* allocate(size_t n);
	static void deallocate(T* ptr);
	static void deallocate(T* ptr, size_t n);

	static void construct(T* ptr);
	static void construct(T* ptr, T& value);
	static void destroy(T* ptr);
	static void destroy(T* first, T* last);
};

template<class T>
T* Allocator<T>::allocate()
{
	return static_cast<T*>(Alloc::allocate(sizeof(T)));
}

template<typename T>
T* Allocator<T>::allocate(size_t n)
{
	return static_cast<T*>(Alloc::allocate(sizeof(T)* n));
}

}

