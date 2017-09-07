//Move semantics
//#include <iostream>
#include <tuple>
#include <vector>
//#include <string>
#include <array>

template<typename T>
class Less_than {
	const T val;		// Value to be compared against
public:
	Less_than(const T& v):val(v){}
	bool operator()(const T& x) const { return x < val; }
};

Less_than<int> Iti{ 42 };
Less_than<char> Its{ 'B' };
void fct(int n, const char & s) {
	bool b1 = Iti(n);
	bool b2 = Its(s);
}

int main() {




	fct(43, 'C');
}

