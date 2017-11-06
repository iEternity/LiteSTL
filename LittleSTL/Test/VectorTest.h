#ifndef _VECTOR_TEST_H_
#define _VECTOR_TEST_H_

#include"../Vector.h"
#include<vector>

namespace LittleSTL{
	namespace VectorTest{

		template<class T>
		using stdVector = std::vector<T>;

		template<class T>
		using myVector = LittleSTL::vector<T>;

		void testCase1();
	}
}

#endif

