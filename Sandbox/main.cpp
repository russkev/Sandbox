//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>

template <typename T, int N>
struct Array_type {
	using type = T;
	static const int dim = N;
};



int main() {
	using Array = Array_type<int, 3>;
	Array::type x;						// x is an int
	constexpr int s = Array::dim;		// s is 3
	int a = 1;
}

