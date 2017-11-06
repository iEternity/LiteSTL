#ifndef _VECTOR_TEST_H_
#define _VECTOR_TEST_H_

#include"../Vector.h"
#include<vector>

namespace LiteSTL{
	namespace VectorTest{

		template<class T>
		using stdVector = std::vector<T>;

		template<class T>
		using myVector = LiteSTL::vector<T>;

		void testCase1();
	}
}

#endif

