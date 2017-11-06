#include"VectorTest.h"
#include<string>
#include<assert.h>
#include"TestUtil.h"

namespace LittleSTL{
	namespace VectorTest{
		void testCase1(){
			stdVector<std::string> vec1(10, "xky");
			myVector<std::string> vec2(10, "xky");

			assert(LittleSTL::Test::containerEqual(vec1, vec2));
		}
	}
}