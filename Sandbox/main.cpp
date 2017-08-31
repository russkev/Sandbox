//Move semantics
//#include <iostream>
#include <tuple>
//#include <string>
//#include <array>

class Nil {};

template<int I, typename T1 = Nil, typename T2 = Nil, typename T3 = Nil, typename T4 = Nil>
struct select;

template<int I, typename T1 = Nil, typename T2 = Nil, typename T3 = Nil, typename T4 = Nil>
using Select = typename select<I, T1, T2, T3, T4>;

// Specializations for 0 - 3:

template<typename T1, typename T2, typename T3, typename T4>
struct select<0, T1, T2, T3, T4> { using type = T1; };

template<typename T1, typename T2, typename T3, typename T4>
struct select<1, T1, T2, T3, T4> { using type = T2; };

template<typename T1, typename T2, typename T3, typename T4>
struct select<2, T1, T2, T3, T4> { using type = T3; };

template<typename T1, typename T2, typename T3, typename T4>
struct select<3, T1, T2, T3, T4> { using type = T4; };

template<int N, typename T1, typename T2, typename T3, typename T4>
Select<N, T1, T2, T3, T4>& get(Tuple<T1, T2, T3, T4>& t);



//template<int N>
//struct Integer {
//	using Error = void;
//	using type = Select<N, Error, signed char, short>;
//};



int main() {

	std::tuple<int, float, char> t(3, 4.5f, 'a');
	auto x = get<2>(t);
	int a = 3;
	//typename Integer<4>::type i4 = 8;
	//typename Integer<1>::type i1 = 9;
}

