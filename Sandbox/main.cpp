//Move semantics
#include <iostream>
#include <tuple>
#include <string>

// INITIALIZATION
template <class... Ts> struct tuple {}; // Base case

template <class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...> { // tuple<T, Ts...> is inherited from tuple<Ts...>
	tuple(T t, Ts... ts) : tuple<Ts...>(ts...), tail(t) {} // Constructor with initializer list

	T tail;
};

// TYPE FUNCTIONS
template <class T, class... Ts>
struct elem_type_holder<0, tuple<T, Ts...>> {
	typedef T type;
};

template <size_t k, class T, class... Ts>
struct elem_type_holder<k, tuple<T, Ts...>> {
	typedef typename elem_type_holder<k - 1, tuple<Ts...>>::type type;
};


// GET
template <size_t k, class... Ts>
typename std::enable_if<
	k == 0, typename elem_type_holder<0, tuple<Ts...>>::type&>::type
	get(tuple<Ts...>& t) {
	return t.tail;
}

template <size_t k, class T, class... Ts>
typename std::enable_if<
	k != 0, typename elem_type_holder<k, tuple<T, Ts...>>::type&>::type
	get(tuple<T, Ts...>& t) {
	tuple<Ts...>& base = t;
	return get<k - 1>(base);
}


template<class T>
struct listType {
	bool isEmpty() const;
	bool isFull() const;
	bool search(const T&) const;
	void insert(const T&);
	void remove(const T&);
	void destroyList();
	void printList();
	listType();
private:
	T list[100];
	int length;
};

template <class T>
void listType<T>::insert(const T& newElement) {
	//function stuff
}




int main() {
	tuple<double, uint64_t, const char*> t1(12.2, 42, "big");
	auto t2 = get<0>(t1);
	int t = 1;
}

