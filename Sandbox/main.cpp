//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <type_traits>

/* WEBSITES
https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
Basic variadif template with tuples
http://aherrmann.github.io/programming/2016/02/28/unpacking-tuples-in-cpp14/
Basic variadic template:
https://thenewcpp.wordpress.com/2011/11/23/variadic-templates-part-1-2/
Teplate Specializations example questions:
http://www.gotw.ca/gotw/049.htm
Integer sequences:
https://blog.galowicz.de/2016/06/24/integer_sequences_at_compile_time/
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


/* VARIADIC TUPLE EXAMPLE

template<class Tuple, size_t... Is>
constexpr auto take_front_impl(Tuple t, std::index_sequence<Is...>) {
	return std::make_tuple(std::get<Is>(t)...);
}

template <size_t N, class Tuple>
constexpr auto take_front(Tuple t) {
	return take_front_impl(t, std::make_index_sequence<N>{});
}
*/

/* VARIADIC LAMBDA*/
template <class F, size_t... Is>
constexpr auto index_apply_impl(F f, std::index_sequence<Is...>) {
	return f(std::integral_constant<size_t, Is>{}...);
}

template <size_t N, class F>
constexpr auto index_apply(F f){
	return index_apply_impl(f, std::make_index_sequence<N>{});
}


template <size_t N, class Tuple>
constexpr auto take_front(Tuple t) {
	return index_apply<N>([&](auto... Is) {
		return std::make_tuple(std::get<Is>(t)...);
	});
}

/* INDEX SEQUENCES

static void func(double d, float f, int i) {
	std::cout
		<< d << ", "
		<< f << ", "
		<< i << "\n";
}

// The following code passes all parameters by value for simplicity

template<typename F, typename TUP, size_t... INDICES>
static void tuple_call(F f, TUP tup, std::index_sequence<INDICES...>) {
	f(std::get<INDICES>(tup)...);
}

template<typename F, typename... Ts>
static void tuple_call(F f, std::tuple<Ts...> tup) {
	constexpr size_t INDICES = sizeof...(Ts);
	std::cout << INDICES << "\n";
	tuple_call(f, tup, std::make_index_sequence<INDICES>{});
}
*/

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
		/* VARIADIC TUPLE EXAMPLE
		std::tuple<int, int, int, int> tupleTest(1, 2, 3, 4);

		auto t = take_front<2>(std::make_tuple(1,2,3,4));
		//size_t temp = take_front(std::make_tuple(1, 2, 3, 4 ));
		//assert(t == std::make_tuple(1, 2));

		//std::tuple<int, bool, char> t2 = std::make_tuple(1, true, 'a');

		//int n = std::get<0>(t2);
		int x = 1;
		*/
	}

	{
		/* VRIADIC LABDA */
		//std::vector<int> items = { 3,50,105,1436 };
		//int factor = 10;
		//auto foundItem = std::find_if(items.begin(), items.end(),
		//	[&factor](int const& b) {
		//	return b * factor == 100;
		//});

		//auto maxElementSize = std::max(items.begin(), items.end(),
		//	[](auto a, auto b) {
		//	return (sizeof(a) > sizeof(b));
		//});


		int first = 5;
		int second = 6;
		auto added = [](auto first, auto second) {
			auto result = first + second;
			return result;
		};
		auto addedB = added(first, second);
		//auto minabs = [](auto... xs) {
		//	return std::min({ abs(xs)... });
		//};

		//assert(1 == minabs(-1, 2, -3));
		int x = 0;
		
	}

	
	{
		/* INDEX SEQUENCE EXAMPLE
		//func(1.0, 2.0f, 3);

		std::tuple<double, float, int> tup(4.0, 5.0f, 6);
		tuple_call(func, tup);

		int x = 1;
		*/
	}
	int x = 1;
}

