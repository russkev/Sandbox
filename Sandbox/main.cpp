//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>

template <typename ...Args> 
struct Args_Test {};

template <typename T, typename ...Args>
struct Args_Test<T, Args...> : Args_Test<Args...> {
	Args_Test(T first, Args ...args) :
		Args_Test<Args...>(args...),
		tail(first)
	{}
	T tail;
};



int main() {
	Args_Test<int, float, char> test(3, 2.5, 'c');
	int a = 4;
}

