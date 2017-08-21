//Move semantics
#include <iostream>
#include <tuple>
#include <string>

template <class... Ts> struct tuple {}; // Base case

template <class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...> { // tuple<T, Ts...> is inherited from tuple<Ts...>
	tuple(T t, Ts... ts) : tuple<Ts...>(ts...), tail(t) {} // Constructor with initializer list

	T tail;
};

template <class T, class... Ts>
struct elem_type_holder<0, tuple<T, Ts...>> {
	typedef T type;
};

template <size_t, class T, class... Ts>
struct elem_type_holder<k, tuple<T, Ts...>> {
	typedef typename elem_type_holder<k - 1, tuple<Ts...>>::type type;
};

int main() {
	tuple<double, uint64_t, const char*> t1(12.2, 42, "big");
	int t = 1;
}

