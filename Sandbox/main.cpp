//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>

//https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
//http://aherrmann.github.io/programming/2016/02/28/unpacking-tuples-in-cpp14/

//First define a type that can hold a parameter pack of indeces
template<size_t... Is>
struct index_sequence;

//Next use parameter pack expansion to index into a generic tuple
template <class Tuple, size_t... Is>
void function(Tuple t, index_sequence<Is...>) {
	some_func(std::get<Is>(t)...);
}

template <typename T, typename... Args>
int some_func(T t, Args... args) {
	return sizeof(t);
}




int main() {
	std::tuple<int, char, float>t1 = { 2, 'a', 5.6f };
	function(t1, index_sequence<0,1,2>);
	int a = 8;

}

