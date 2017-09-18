//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>
#include <vector>

//https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
//http://aherrmann.github.io/programming/2016/02/28/unpacking-tuples-in-cpp14/
//https://thenewcpp.wordpress.com/2011/11/23/variadic-templates-part-1-2/

template<typename... Args>
struct Biggest;

template<typename First>
struct Biggest<First> {
	using type = First;
};

template<typename First, typename... Args>
struct Biggest<First, Args...> {
	using next = typename Biggest<Args...>::type;
	using type = typename std::conditional<sizeof(First) < sizeof(next), next, First>::type;
};



int main() {
	int a = 1;
	float b = 2.3f;
	double c = 4.65;

	using BA = Biggest<int, char, double>::type;
	BA BB = 45;

	int x = 1;

}

