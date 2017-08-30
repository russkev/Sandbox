//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>

//https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/

template <class... T_values>
class Base {
	virtual void something(T_values... values) = 0;
};

class Derived1 : public Base<int, short, double> {
public:
	void something(int a, short b, double c) override;
};

class Derived2 : public Base<std::string, char> {
	void something(std::string a, char b) override;
};





int main() {
	Base.something(int a);

}

