//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>
#include <vector>

/* WEBSITES
https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
Basic variadif template with tuples
http://aherrmann.github.io/programming/2016/02/28/unpacking-tuples-in-cpp14/
Basic variadic template:
https://thenewcpp.wordpress.com/2011/11/23/variadic-templates-part-1-2/
Teplate Specializations example questions:
http://www.gotw.ca/gotw/049.htm
*/

/* Template Specialization Answers
a = 10 y
b = 8  y
c = 3  y
d = 2  y
e = 1  y
f = 9  y
g = 6  y
h = 7  y
i = 5  y
j = 4  y
k = 1  y
l = 3  y




*/


/* VARIADIC TUPLE EXAMPLE */
template<size_t... Is>
struct index_sequence;

template<class Tuple, size_t... Is>
constexpr auto take_front_impl(Tuple t, index_sequence<Is...>) {
	return make_tuple(std::get<Is>(t)...);
}

template <size_t N, class Tuple>
constexpr auto take_front(Tuple t) {
	return take_front_impl(t, std::make_index_sequence<N>{})
}



/* VARIADIC EXAMPLE
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
*/



int main() {
	int a = 1;
	float b = 2.3f;
	double c = 4.65;

	{
		/* VARIADIC EXAMPLE
		using BA = Biggest<int, char, double>::type;
		BA BB = 45;
		*/
	}

	{
		/* VARIADIC TUPLE EXAMPLE */
		std::tuple<int, int, int, int> tupleTest(1, 2, 3, 4);

		auto t1 = take_front<2>(tupleTest);
		//assert(t = make_tuple(1, 2));

		std::tuple<int, bool, char> t2 = std::make_tuple(1, true, 'a');

		int n = std::get<0>(t2);
	}
	int x = 1;
}

