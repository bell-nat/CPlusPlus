#include "Task2.h"
#include <format>
#include "Io.h"

using namespace std;

Task2::Task2()
{
	_month[1] = 31;
	_month[2] = 28;
	_month[3] = 31;
	_month[4] = 30;
	_month[5] = 31;
	_month[6] = 30;
	_month[7] = 31;
	_month[8] = 31;
	_month[9] = 30;
	_month[10] = 31;
	_month[11] = 30;
	_month[12] = 31;
}

auto Task2::Query2() -> void
{
	Io::Output(L"Введите сторону \"A\": ", false);
	const auto a = Io::GetDouble();
	Io::Output(L"Введите сторону \"B\": ", false);
	const auto b = Io::GetDouble();
	Io::Output(L"Введите сторону \"C\": ", false);
	const auto c = Io::GetDouble();

	if(a == b == c)
	{
		Io::Output(L"Треугольник равносторонний");
		return;
	}

	if(a == b || b == c || a == c)
	{
		Io::Output(L"Треугольник равнобедренный");
		return;
	}


	if(a + b < c || a + c < b || b + c < a)
	{
		Io::Output(L"Фигура не является треугольником");
		return;
	}

	if (a + b == c || a + c == b || b + c == a)
	{
		Io::Output(L"Треугольник вырожденный");
		return;
	}

	if
	(
		pow(a, 2) + pow(b, 2) == pow(c, 2) ||
		pow(b, 2) + pow(c, 2) == pow(a, 2) ||
		pow(c, 2) + pow(a, 2) == pow(b, 2)
	)
	{
		Io::Output(L"Треугольник прямоугольный");
		return;
	}

	if (a <= 0 || b <= 0 || c <= 0)
	{
		Io::Output(L"некорректные входные данные");
		return;
	}
	
	Io::Output(L"Произвольный прямоугольный");
}

auto Task2::Query3() -> void
{
	Io::Output(L"Введите номер дня: ", false);
	const auto day = Io::GetInt(1, 31);
	Io::Output(L"Введите номер месяца: ", false);
	const auto month = Io::GetInt(1, 12);
	Io::Output(L"Укажите тип года. невисокосный/високосный(0/1): ", false);
	const auto yearType = Io::GetInt(0, 1);

	auto maxDay = _month[month];
	if (month == 2 && yearType == 1) { maxDay++; }
	if (day > maxDay)
	{
		const auto error = format
		(
			L"Ошибка, вы указали {} дней, но в {} месяце дней: {}",
			day,
			month,
			maxDay
		);
		Io::Output(error);
		return;
	}

	auto sumDay = day;
	for (int i = 1; i < month; i++)
	{
		if (i == 2 && yearType == 1 && day != 29)
		{
			sumDay++;
		}
		sumDay += _month[i];
	}

	const auto result = format
	(
		L"По дате: {}.{} {}. Дней с первого дня: {}",
		day,
		month,
		yearType == 0 ? L"не високосный год" : L"високосный год",
		sumDay
	);
	Io::Output(result);
}