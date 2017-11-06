#pragma once

#include<iterator>

namespace LiteSTL
{
namespace Test
{

template<class Container1, class Container2>
bool containerEqual(Container1& con1, Container2& con2){
	auto first1 = std::begin(con1);
	auto last1 = std::end(con1);
	auto first2 = std::begin(con2);
	auto last2 = std::end(con2);

	for (; first1 != last1 && first2 != last2; first1++, first2++){
		if (*first1 != *first2){
			return false;
		}
	}

	return (first1 == last1 && first2 == last2);
}

}//namespace Test
}//namespace LiteSTL