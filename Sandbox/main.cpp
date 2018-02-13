//QuickSort
#include <iostream>

#include <vector>

template<typename T>
void quickSort(std::vector<T>& s_vec)
{
	if (s_vec.size() < 2)
	{
		return;
	}

	auto pivot = s_vec.at(0);
	std::vector<T> v_greater;
	std::vector<T> v_less;
	std::vector<T> v_pivot;

	for (auto & i : s_vec)
	{
		if (i > pivot)
		{
			v_greater.push_back(i);
		}
		else if (i < pivot)
		{
			v_less.push_back(i);
		}
		else
		{
			v_pivot.push_back(i);
		}
	}
	quickSort(v_greater);
	quickSort(v_less);
	std::vector<T> outVector;

	outVector.reserve(v_less.size() + v_pivot.size() + v_greater.size());
	outVector.insert(outVector.end(), v_less.begin(), v_less.end());
	outVector.insert(outVector.end(), v_pivot.begin(), v_pivot.end());
	outVector.insert(outVector.end(), v_greater.begin(), v_greater.end());

	s_vec = outVector;

	return;

}

int main() {


	std::vector<int> numList		= { 54, 5, 3, 9, 0, -2, 10, 12, 45, 23, 12, 12, -23, 9, 345, 23 };

	quickSort(numList);

	auto x = 0;
}

