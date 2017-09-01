//Move semantics
//#include <iostream>
#include <tuple>
//#include <string>
//#include <array>

template<unsigned N, typename... Cases> // General case, never instantiated
struct select {};

template<unsigned N, typename T, typename... Cases>
struct select<N, T, Cases...> : select<N - 1, Cases...> {
};

template <typename T, typename... Cases>
struct select<0, T, Cases...> {
	using type = T;
};

template <unsigned N, typename... Cases>
using Select = typename select<N, Cases...>::type;

template<int N>
struct Integer {
	using Error = void;
	using type = Select < N, Error, signed char, short, Error, int, Error, Error, Error, long>;
};

int main() {

	typename Integer<4>::type i4 = 8;
	typename Integer<1>::type i1 = 9;
	int a = 0;
}

