#pragma once

#include "..\Vector.h"
#include <vector>

namespace LiteSTL
{
namespace VectorTest
{

template<class T>
using stdVector = std::vector<T>;

template<class T>
using myVector = LiteSTL::Vector<T>;

void testCase1();

}
}

