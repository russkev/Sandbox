//Move semantics
#include <iostream>

#include <vector>




int main() {


	std::vector<int> numList		= { 54, 5, 3, 9, 0, -2, 10, 12, 45, 23, 12, 12, -23, 9, 345, 23 };
	std::vector<int> sortedList		= { numList.at(0) };

	for (auto i = 1; i < numList.size(); ++i)
	{
		std::cout << i;
		auto it_start			= sortedList.begin();
		auto it_end				= sortedList.end();
		auto it_middle			= it_start + (sortedList.size() / 2);
		auto it_insert_point	= it_start;

		//while (it_start != it_end || it_start + 1 != it_end)
		//while (it_start != it_middle)
		while (it_start + 1 != it_end)
		{
			if (numList[i] == *it_middle)
			{
				it_insert_point = it_middle;
				break;
			}
			if (numList[i] > *it_middle)
			{
				it_start		= it_middle;
				it_middle		= it_middle + ((it_end - it_middle) / 2);
				it_insert_point = it_middle + 1;
			}
			else
			{
				it_end			= it_middle;
				it_middle		= it_middle - ((it_middle - it_start) / 2);
				it_insert_point = it_middle;
			}
		}
		sortedList.insert(it_insert_point, numList[i]);
	}
	auto x = 0;
}

