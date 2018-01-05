//Move semantics
#include <iostream>
#include <tuple>
#include <string>
#include <array>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <type_traits>
#include <functional>
#include <utility>

/* WEBSITES
https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
Basic variadif template with tuples
http://aherrmann.github.io/programming/2016/02/28/unpacking-tuples-in-cpp14/
Basic variadic template:
https://thenewcpp.wordpress.com/2011/11/23/variadic-templates-part-1-2/
Teplate Specializations example questions:
http://www.gotw.ca/gotw/049.htm
Integer sequences:
https://blog.galowicz.de/2016/06/24/integer_sequences_at_compile_time/
*/

#define GET_VARIABLE_NAME(var) (#var)

int main() 
{
	int a = 5;
	std::string a2 = GET_VARIABLE_NAME(a);


	return 0;
}
