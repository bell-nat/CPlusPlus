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
}

auto Task2::Query3() -> void
{
	const auto day = Io::GetInt(1, 31);
	const auto month = Io::GetInt(1, 12);
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
		if (i == 2 && yearType == 1)
		{
			sumDay++;
		}
		sumDay += _month[i];
	}

	const auto result = format
	(
		L"По дате: {}.{} {}. Дней с 1 для: {}",
		day,
		month,
		yearType == 0 ? L"не високосный год" : L"високосный год",
		sumDay
	);
	Io::Output(result);
}