#pragma once

class Task1
{
public:
	Task1() = default;
	~Task1() = default;
	/// <summary>
    /// 1. Пользователь вводит два числа.
    /// Оба числа не являются нулём.
    /// Вывести их сумму, разность, произведение, частное.
    /// </summary>
	auto Query1() -> void;
	/// <summary>
	///	2. Пользователь вводит число.
	///	Вывести на экран квадрат, куб и четвёртую степень этого числа.
	/// </summary>
	auto Query2() -> void;
private:
	auto Sum(int first, int second) -> int;
	auto Subtraction(int first, int second) -> int;
	auto Multiplication(int first, int second) -> int;
	auto Division(int first, int second) -> float;
	auto Pow(int number, int multiplier) -> int;
};