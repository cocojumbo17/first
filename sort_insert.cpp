// sort_insert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <ctime>
#include <iostream>

void sort_insert(std::vector<int>& data, int& check, int& swapping)
{
	size_t data_size = data.size();
	for (size_t i = 1; i < data_size; ++i)
	{
		int cur_val = data[i];
		int j = i - 1;
		int ii = i;
		while (j >= 0)
		{
			int check_val = data[j];
			++check;
			if (cur_val < check_val)
			{
				std::iter_swap(data.begin() + ii, data.begin() + j);
				--ii;
				++swapping;
				--j;
			}
			else
				break;
		}
	}
}

void sort_bubble(std::vector<int>& data, int& check, int& swapping)
{
	size_t data_size = data.size();
	for (size_t i = 0; i < data_size-1; ++i)
	{
		bool is_no_changed = true;
		for (size_t j = 0; j < data_size - 1 - i; ++j)
		{
			++check;
			if (data[j] > data[j + 1])
			{
				std::iter_swap(data.begin() + j, data.begin() + j + 1);
				is_no_changed = false;
				++swapping;
			}
		}
		if (is_no_changed)
			break;
	}
}

int main()
{
	const int NUMBER_COUNT = 1000;
	std::vector<int> data;
	data.reserve(1000);
	srand(time(nullptr));
	for (size_t i = 0; i < NUMBER_COUNT; ++i)
	{
		int val = rand();
		data.push_back(val);
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::vector<int> data2(data);

	int check=0, swapping=0;
	sort_insert(data, check, swapping);
	
	std::cout << "\n\n\nresult of sort_insert\n\n";
	for (size_t i = 0; i < NUMBER_COUNT; ++i)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "check=" << check << std::endl;
	std::cout << "swapping=" << swapping << std::endl;

	check = 0;
	swapping = 0;
	sort_bubble(data2, check, swapping);

	std::cout << "\n\n\nresult of sort_bubble\n\n";
	for (size_t i = 0; i < NUMBER_COUNT; ++i)
	{
		std::cout << data2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "check=" << check << std::endl;
	std::cout << "swapping=" << swapping << std::endl;


	return 0;
}

