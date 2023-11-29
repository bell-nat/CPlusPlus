#pragma once
#include <vector>

class Task3
{
public:
	Task3() = default;
	~Task3() = default;
	/// <summary>
	/// 2. Дано целое число, не меньшее двух.
	/// Вывести:
	/// 1) его наименьший натуральный делитель, отличный от 1;
	/// 2) список всех натуральных делителей данного числа;
	/// 3) «простое», если число является таковым и «не является простым» иначе.
	/// </summary>
	auto Query2() -> void;
	/// <summary>
	/// 1. Дано натуральное число N.
	/// Вывести ближайшую к этому числу степень двойки, тройки и пятёрки.
	/// </summary>
	auto Query3() -> void;
private:
	auto GetDegree(int digital, int number) -> int;
	auto GetDivisor(int digital) -> int;
	auto GetDivisors(int digital) -> std::vector<int>;
	auto CheckPrime(int digital) -> bool;
};
