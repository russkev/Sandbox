//Move semantics
#include <iostream>
#include <tuple>
#include <string>

template<typename T>
bool pair_comparer(T a) {
	return false;
}

template<typename T1, typename T2>
bool pair_comparer(T1 a, T2 b) {
	return std::common_type<T1, T2>::type(a) == std::common_type<T1, T2>::type(b);
}

template<typename T1, typename T2, typename... Args>
bool pair_comparer(T1 a, T2 b, Args... args) {
	return std::common_type<T1, T2>::type(a) == std::common_type<T1, T2>::type(b) && pair_comparer(args...);
}

int main() {
	bool temp = pair_comparer(3, 3.0f, 4, 4.0f);
		
	int a = 1;
}

