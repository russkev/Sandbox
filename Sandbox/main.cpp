//QuickSort
#include <iostream>

#include <vector>



template<typename T>
std::vector<T> combineThreeVectors(std::vector<T> s_vec_1, std::vector<T> s_vec_2, std::vector<T> s_vec_3)
{
	std::vector<T> outVector;
	outVector.reserve(s_vec_1.size() + s_vec_2.size() + s_vec_3.size());
	outVector.insert(outVector.end(), s_vec_1.begin(), s_vec_1.end());
	outVector.insert(outVector.end(), s_vec_2.begin(), s_vec_2.end());
	outVector.insert(outVector.end(), s_vec_3.begin(), s_vec_3.end());
	return outVector;
}

template<typename T>
void quickSort(std::vector<T>& s_vec)
{
	if (s_vec.size() < 2)
	{
		return;
	}
	auto pivot = s_vec.at(0);

	std::vector<T> v_less;
	std::vector<T> v_greater;
	std::vector<T> v_pivot;

	for (auto & i : s_vec)
	{
		if (i < pivot)
		{
			v_less.push_back(i);
		}
		else if (i > pivot)
		{
			v_greater.push_back(i);
		}
		else
		{
			v_pivot.push_back(i);
		}
	}
	quickSort(v_less);
	quickSort(v_greater);
	s_vec = combineThreeVectors(v_less, v_pivot, v_greater);
	return;
}

int main() {


	std::vector<int> numList		= { 54, 5, 3, 9, 0, -2, 10, 12, 45, 23, 12, 12, -23, 9, 345, 23 };

	quickSort(numList);

	auto x = 0;
}

