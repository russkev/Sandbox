//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>

//https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
//http://aherrmann.github.io/programming/2016/02/28/unpacking-tuples-in-cpp14/

//template<unsigned...> struct index_sequence { 
//	using type = index_sequence; 
//};
//
//template<unsigned... I1, unsigned... I2>
//struct concat<index_sequence<I1...>, index_sequence<I2...>>
//	: seq<I1..., (sizeof...(I1)+I2)...> {};
//
//template<class S1, class S2>
//using Concat = Invoke<concat<S1, S2>>;
//
//
////First define a type that can hold a parameter pack of indeces
//template<size_t... Is>
//struct index_sequence;
//
////Next use parameter pack expansion to index into a generic tuple
//template <class Tuple, size_t... Is>
//void function(Tuple t, index_sequence<Is...>) {
//	some_func(std::get<Is>(t)...);
//}
//
//template <typename T, typename... Args>
//int some_func(T t, Args... args) {
//	return sizeof(t);
//}

//template <class Tuple, size_t... Is>
//constexpr auto take_front_impl(Tuple t, std::index_sequence<Is...>) {
//	return make_tuple(get<Is>(t)(t)...)
//}
//
//template <size_t N, class Tuple>
//constexpr auto take_front(Tuple t) {
//	return take_front_impl(t, std::make_index_sequence<N>{});
//}

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

	std::tuple<int, char, float>t1 ( 2, 'a', 5.6f );
	//function(t1, index_sequence<0,1,2>);
	int z = 8;

}

