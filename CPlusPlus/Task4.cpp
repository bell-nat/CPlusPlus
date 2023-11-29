#include "Task4.h"

#include <algorithm>
#include <format>
#include <vector>

#include "Extension.h"
#include "Io.h"

auto Task4::Query1() -> void
{
	Io::Output(L"Укажите размер первого списка: ", false);
	const auto sizeFirst = Io::GetInt(0);
	vector<int> firstArray(sizeFirst, 0);
	for (auto i = 0; i < sizeFirst; i++)
	{
		Io::Output(L"Укажите значение для списка: ", false);
		firstArray[i] = Io::GetInt();
	}
	Io::Output(L"Вы ввели: ", false);
	Io::Output(Extension::Join(firstArray, ", "));
	ranges::reverse(firstArray);

	Io::Output(L"Укажите размер второго списка: ", false);
	const auto sizeSecond= Io::GetInt(0);
	vector<int> secondArray(sizeSecond, 0);
	for (auto i = 0; i < sizeSecond; i++)
	{
		Io::Output(L"Укажите значение для списка: ", false);
		secondArray[i] = Io::GetInt();
	}
	Io::Output(L"Вы ввели: ", false);
	Io::Output(Extension::Join(secondArray, ", "));

	Io::Output(L"Укажите абсолютную величину: ", false);
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
	Io::Output(L"Результирующий список: ", false);
	Io::Output(result);
}

auto Task4::Query2() -> void
{
	Io::Output(L"Укажите размер первого списка: ", false);
	const auto size = Io::GetInt(0);
	vector<int> numbers(size, 0);
	for (auto i = 0; i < size; i++)
	{
		Io::Output(L"Укажите значение для списка: ", false);
		numbers[i] = Io::GetInt();
	}
	Io::Output(L"Вы ввели: ", false);
	Io::Output(Extension::Join(numbers, ", "));

	ranges::rotate(numbers, numbers.end() - 1);
	Io::Output(L"Массив после сдвига: ", false);
	Io::Output(Extension::Join(numbers, ", "));
}