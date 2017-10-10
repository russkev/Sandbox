//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <type_traits>
#include <functional>
#include <utility>

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

// Index Apply Implementation
template <class F, size_t... Is>
constexpr auto index_apply_impl(F f, std::index_sequence<Is...>) {
	return f(std::integral_constant<size_t, Is>{}...);
}

// Index Apply
template <size_t N, class F>
constexpr auto index_apply(F f){
	return index_apply_impl(f, std::make_index_sequence<N>{});
}

// Apply1 Implementation
template <class Tuple, class F, size_t... Is>
constexpr auto apply_impl(Tuple t, F f, std::index_sequence<Is...>) {
	return f(std::get<Is>(t)...);
}

// Apply1
template <class Tuple, class F>
constexpr auto apply(Tuple t, F f) {
	return apply_impl(
		t, f, std::make_index_sequence < std::tuple_size<Tuple>::value > {});
}

// Apply2
template <class Tuple, class F>
constexpr auto apply2(Tuple T, F f) {
	return index_apply< std::tuple_size<Tuple>::value > (
		[&T, &f](auto... Is) {
		return f(std::get<Is>(T)...); 
	});
}

// Take Front
template <size_t N, class... Ts>
constexpr auto take_front(std::tuple<Ts...> t) {
	return index_apply<N>(
		[&](auto... Is) {
		return std::make_tuple(std::get<Is>(t)...);
	});
}

// Reverse
template <class Tuple>
constexpr auto reverse(Tuple T) {
	return index_apply<std::tuple_size<Tuple>::value>(
		[&](auto... Is) {
		return std::make_tuple(
			std::get < std::tuple_size<Tuple>{} -1 - Is > (T)...);
	});
}

// Take back
template <size_t N, class T>
constexpr auto take_back(T t) {
	return index_apply<N>(
		[&](auto... Is) {
		return std::make_tuple(
			std::get < std::tuple_size<T>{} -N + Is > (t)...);
	});
}


// Zip
template <class... Tuples>
constexpr auto zip(Tuples... ts) {
	constexpr size_t len = std::min({ std::tuple_size<Tuples>::value... });
	auto row =
		[&](auto I) { return std::make_tuple(std::get<I>(ts)...); };
	return index_apply<len>(
		[&](auto ...Is) { return std::make_tuple(row(Is)...); });
}

constexpr auto zip() { return std::make_tuple(); }

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

/* VARIADIC TMPLATES WITH CLASSES */


template <typename... Args>
struct Base {
	Base(std::tuple<Args...> t) :m_values(t) {};
	
	void printSizeOfs_impl() {};

	template<typename Head, typename... Tail>
	void printSizeOfs_impl(const Head & head, const Tail &... tail) {
		std::cout << sizeof(head) << "\n";
		printSizeOfs_impl(tail...);
	}

	void printSizeOfs() {
		printSizeOfs_impl(std::get<Args>(m_values)...);
	}
private:
	std::tuple<Args...> m_values;
};


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
		/* VARIADIC TUPLE EXAMPLE*/
		std::tuple<int, int, int, int> tupleTest(1, 2, 3, 4);

		auto x0 = take_front<2>(std::make_tuple(1,2,3,4));

		auto x1 = apply(std::make_tuple(1, 2), std::plus<>{});

		auto x2 = apply2(std::make_tuple(1, 2), std::plus<>{});

		auto x3 = apply2(std::make_tuple(2, 3, 4), [](int x, int y, int z) {return x*y*z; });

		auto x4 = reverse(std::make_tuple(4, 7, 8));

		auto x5 = take_back<2>(std::make_tuple(1, 2, 3, 4, 5, 6, 7));

		auto x6 = zip(
			std::make_tuple(1, 2),
			std::make_tuple(3, 4),
			std::make_tuple(5, 6));

		assert(x6 == std::make_tuple(
			std::make_tuple(1, 3, 5),
			std::make_tuple(2, 4, 6)));

		auto x7 = zip(
			std::make_tuple(1, 2, 3),
			std::make_tuple(4));

		assert(x7 == std::make_tuple(std::make_tuple(1, 4)));



		//size_t temp = take_front(std::make_tuple(1, 2, 3, 4 ));
		//assert(t == std::make_tuple(1, 2));

		//std::tuple<int, bool, char> t2 = std::make_tuple(1, true, 'a');

		//int n = std::get<0>(t2);
		int x = 1;
	}

	{
		auto B0 = std::make_tuple(1, 2.3f, 'a');
		
		Base<int, float, char> B1(B0);
		B1.printSizeOfs();

		int Bx = 1;

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

