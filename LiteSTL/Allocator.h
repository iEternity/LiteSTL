#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

namespace LiteSTL{
	template<class T>
	class allocator{
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
	T* allocator<T>::allocate(){
		return static_cast<T*>(alloc::allocate(sizeof(T)));
	}
}

#endif