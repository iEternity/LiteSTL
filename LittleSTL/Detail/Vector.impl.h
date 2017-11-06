#ifndef _VECTOR_IMPL_H_
#define _VECTOR_IMPL_H_

#include"../Vector.h"

namespace LittleSTL{
	template<class T, class Alloc>
	vector<T, Alloc>::vector(const size_type n, const value_type& value){
		allocateAndFillN(n, value);
	}

	template<class T, class Alloc>
	vector<T, Alloc>::allocateAndFillN(const size_type n, const value_type value){
		dataAllocator::alloc(sizeof(n*value));
	}
}

#endif