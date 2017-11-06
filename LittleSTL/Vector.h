#ifndef _VECTOR_H_
#define _VECTOR_H_

#include"Allocator.h"

namespace LittleSTL{
	
	template<class T, class Alloc = allocator<T>>
	class vector{
	private:
		typedef Alloc dataAllocator;
		T* start_;
		T* finish_;
		T* endOfStorage_;

	public:
		typedef T					value_type;
		typedef T*					iterator;
		typedef const T*			const_iterator;
		typedef size_t				size_type;

	public:
		/*构造 赋值 析构等函数*/
		vector()
			:start_(0),finish_(0),endOfStorage_(0){}
		vector(const size_type n, const value_type& value); 

		/*迭代器*/
		iterator begin(){ return start_; }
		iterator end(){ return finish_; }

	private:
		void allocateAndFillN(const size_type n, const value_type& value);
	};
}

#include"../Detail/Vector.impl.h"
#endif