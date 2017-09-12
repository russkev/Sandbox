//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>
#include <vector>

//https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
//http://aherrmann.github.io/programming/2016/02/28/unpacking-tuples-in-cpp14/
//https://thenewcpp.wordpress.com/2011/11/23/variadic-templates-part-1-2/



template<size_t... Entries>
struct StaticArray
{
	std::vector<size_t> m_vec = { Entries... };
	size_t m_array [sizeof...(Entries)] = { Entries... };
};

template<typename... Args>
struct find_biggest;

//If there is only one thing, it is the biggest
template<typename First>
struct find_biggest<First>
{
	typedef First type;
};

//The biggest of everything in Args and First
template <typename First, typename... Args>
struct find_biggest<First, Args...>
{
	typedef typename find_biggest<Args...>::type next;
	typedef typename std::conditional<
		sizeof(First) >= sizeof(next),
		First,
		next
	>::type type;
};

template <typename... Args>
struct find_last;

template <typename First>
struct find_last<First> {
	typedef First type;
};

template <typename First, typename... Args>
struct find_last<First, Args...> {
	typedef typename find_last<Args...>::type type;
};



int main() {
	int a = 1;
	float b = 2.3f;
	double c = 4.65;
	StaticArray<3, 4, 5, 8, 9, 10> sa1;

	typedef find_biggest<char, float, double>::type fb_type;
	typedef find_last<int, double, char>::type ff_type;

	fb_type fb2 = 23;
	ff_type ff2 = 24;

	std::tuple<int, char, float>t1 ( 2, 'a', 5.6f );
	//function(t1, index_sequence<0,1,2>);
	int z = 8;

}

