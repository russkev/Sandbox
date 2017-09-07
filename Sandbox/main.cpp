//Move semantics
//#include <iostream>
#include <tuple>
#include <vector>
//#include <string>
#include <array>

template<typename T>
struct On_heap {
	On_heap() :p(new T) {}		//allocate
	~On_heap() { delete p; }	//deallocate

	T& operator*() { return *p; }
	T* operator->() { return p; }

	On_heap(const On_heap&)				= delete;	//prevent copying
	On_heap& operator=(const On_heap&)	= delete;	//prevent assigning
private:
	T* p;
};

template<typename T>
struct Scoped {
	Scoped() {}

	T& operator*() { return x; }
	T* operator->() { return &x; }

	Scoped(const Scoped&)				= delete;
	Scoped& operator = (const Scoped&)	= delete;
private:
	T x;
};

constexpr int on_stack_max = sizeof(std::string);	//Max size of object we want on stack

template<typename T>
struct Obj_holder {
	typedef typename std::conditional < (sizeof(T) <= on_stack_max), Scoped<T>, On_heap<T>>::type type;
	//using type = On_heap<T>; // typename std::conditional < (sizeof(T) <= on_stack_max), Scoped<T>, On_heap<T>> ::type;
};

void f() {
	typename Obj_holder<double>::type v1;
	typename Obj_holder<std::array<double, 200>>::type v2;

	*v1 = 7.7;
	(*v2)[77] = 9.9;
}

//template <typename T>
//using Holder = typename Obj_holder<T>::type;
//
//void f2() {
//	Holder<double> v1;					// The double goes on the stack
//	Holder<std::array<double, 200>> v2;	// The array goes on the free store
//	*v1 = 7.7;							// Scoped provides pointer like access
//	(*v2)[77] = 9.9;					// On_heap provides pointer like access
//}

int main() {


	f();

	int a = 0;
}

