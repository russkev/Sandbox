//Move semantics
#include <iostream>

#include <vector>

//template <typename T>
//void dSort(std::vector<T> &s_vec, T s_num, int s_start, int s_end)
//{
//	if (s_start == s_end)
//	{
//		s_vec.insert(s_vec.begin() + s_start, s_num);
//	}
//	else
//	{
//		int middle = ((s_end - s_start) / 2);
//		if (middle < s_start)
//		{
//			middle = s_start;
//		}
//		if (middle > s_end)
//		{
//			middle = s_end;
//		}
//		if (s_num > s_vec.at(middle))
//		{
//			dSort(s_vec, s_num, middle, s_end);
//		}
//		else
//		{
//			dSort(s_vec, s_num, s_start, middle);
//		}
//	}
//}

template<typename T>
std::vector<T> dSort(std::vector<T> s_vec)
{
	if (s_vec.size() < 2)
	{
		return s_vec;
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
		if (i < pivot)
		{
			v_less.push_back(i);
		}
		else
		{
			v_pivot.push_back(i);
		}
	}
	dSort(v_greater);
	dSort(v_less);
	std::vector<T> outVector;

	outVector.reserve(v_less.size() + v_pivot.size() + v_greater.size());
	outVector.insert(outVector.end(), v_less.begin(), v_less.end());
	outVector.insert(outVector.end(), v_pivot.begin(), v_pivot.end());
	outVector.insert(outVector.end(), v_greater.begin(), v_greater.end());

	return outVector;

}

int main() {


	std::vector<int> numList		= { 54, 5, 3, 9, 0, -2, 10, 12, 45, 23, 12, 12, -23, 9, 345, 23 };
	std::vector<int> sortedList;// = { numList.at(0) };

	sortedList = dSort(numList);

	//for (auto & i : numList)
	//{
	//	dSort<int>(sortedList, i, 0, sortedList.size());
	//}

	//for (auto i = 1; i < numList.size(); ++i)
	//{
	//	std::cout << i;
	//	auto it_start			= sortedList.rend();
	//	auto it_end				= sortedList.end();
	//	auto it_middle			= it_start + (sortedList.size() / 2);
	//	auto it_insert_point	= it_start;

	//	//while (it_start != it_end || it_start + 1 != it_end)
	//	//while (it_start != it_middle)
	//	while (*(it_start + 1) != *it_end)
	//	{
	//		//if (numList[i] == *it_middle)
	//		//{
	//		//	it_insert_point = it_middle;
	//		//	break;
	//		//}
	//		if (numList[i] > *it_middle)
	//		{
	//			it_start		= it_middle;
	//			it_middle		= it_middle + ((it_start - it_middle) / 2);
	//			it_insert_point = it_middle + 1;
	//		}
	//		else
	//		{
	//			it_end			-= (it_middle - it_start);
	//			it_middle		= it_middle - ((it_middle - it_start) / 2);
	//			it_insert_point = it_middle;
	//		}
	//	}
	//	sortedList.insert(it_insert_point, numList[i]);
	//}
	auto x = 0;
}

