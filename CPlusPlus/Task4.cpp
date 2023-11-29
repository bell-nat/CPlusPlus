#include "Task4.h"

#include <algorithm>
#include <format>
#include <vector>

#include "Extension.h"
#include "Io.h"

auto Task4::Query1() -> void
{
	const auto sizeFirst = Io::GetInt(0);
	vector<int> firstArray(sizeFirst, 0);
	for (auto i = 0; i < sizeFirst; i++)
	{
		firstArray[i] = Io::GetInt();
	}
	ranges::reverse(firstArray);

	const auto sizeSecond= Io::GetInt(0);
	vector<int> secondArray(sizeSecond, 0);
	for (auto i = 0; i < sizeSecond; i++)
	{
		secondArray[i] = Io::GetInt();
	}

	const auto max = Io::GetInt();	
	erase_if(firstArray, [max](const int& item) {return item > max; });

	string result;
	if(secondArray.empty() && firstArray.empty())
	{
		result = "Нет элементов";
	}
	if(secondArray.empty())
	{
		result = Extension::Join(firstArray, ", ");
	}
	else if(firstArray.empty())
	{
		result = Extension::Join(secondArray, ", ");
	}
	else
	{
		secondArray.insert(secondArray.begin(), firstArray.begin(), firstArray.end());
		result = Extension::Join(secondArray, ", ");
	}
	Io::Output(result);
}

auto Task4::Query2() -> void
{
	const auto size = Io::GetInt(0);
	vector<int> numbers(size, 0);
	for (auto i = 0; i < size; i++)
	{
		numbers[i] = Io::GetInt();
	}
	const auto initArray = Extension::Join(numbers, ", ");
	Io::Output(format("Вы ввели массив: {}", initArray));
	ranges::rotate(numbers, numbers.end() - 1);
	const auto result = format("Массив после сдвига {}", Extension::Join(numbers, ", "));
	Io::Output(result);
}