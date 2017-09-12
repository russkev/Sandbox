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
	//enum {N = 4};
	//enum { N = sizeof...(Entries) };
	//size_t m_size = sizeof... (Entries);
	std::vector<size_t> m_vec = { Entries... };
	size_t m_array [sizeof...(Entries)] = { Entries... };
};




template <typename T, typename ...Args>
T t1(T t, Args... args) {
	return t1(args...);
}

template <typename T>
T t1(T t) {
	return t;
}


int main() {
	int a = 1;
	float b = 2.3f;
	double c = 4.65;
	auto test = t1(a, b, c);
	StaticArray<3, 4, 5, 8, 9, 10> sa1;

	std::tuple<int, char, float>t1 ( 2, 'a', 5.6f );
	//function(t1, index_sequence<0,1,2>);
	int z = 8;

}

