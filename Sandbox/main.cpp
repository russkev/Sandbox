//Move semantics
#include <iostream>

#include <vector>




int main() {


	std::vector<int> numList = { 54, 5, 3, 9, 0, -2, 10, 12, 45, 23, 12, 12, 9, 345, 23 };
	std::vector<int> sortedList = { numList.at(0) };

	for (auto i = 1; i < numList.size(); ++i)
	{
		std::cout << i;
		auto start	= sortedList.begin();
		auto end	= sortedList.end();
		auto middle = start + (sortedList.size() / 2);

		while (start != end)
		{
			if (numList[i] > *middle)
			{
				start = middle;
				middle = middle + ((end - middle) / 2);
			}
			else
			{
				end = middle;
				middle = middle - ((middle - start) / 2);
			}
		}
		sortedList.insert(middle, numList[i]);
	}
	auto x = 0;
}

