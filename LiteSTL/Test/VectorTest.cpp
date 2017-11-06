#include"VectorTest.h"
#include<string>
#include<assert.h>
#include"TestUtil.h"

using namespace LiteSTL;
using namespace VectorTest;

void testCase1()
{
	stdVector<std::string> vec1(10, "zhangkuo");
	myVector<std::string> vec2(10, "zhangkuo");

	assert(LiteSTL::Test::containerEqual(vec1, vec2));
}
