#include "Task1.h"
#include "Io.h"
#include <iostream>
#include <cmath>
#include "Extension.h"

using namespace std;

Task1::Task1() = default;

Task1::~Task1() = default;

auto Task1::Query1() -> void
{
	const auto first = Io::GetInt();
	const auto second = Io::GetInt();
    Io::Output(L"Сумма: " + to_wstring(Sum(first, second)));
    Io::Output(L"Разность: " + to_wstring(Subtraction(first, second)));
    Io::Output(L"Произведение: " + to_wstring(Multy(first, second)));
    Io::Output(L"Частное: " + to_wstring(Division(first, second)));    
    Io::Output(L"");
}

auto Task1::Query2() -> void
{
	const auto number = Io::GetInt();
    auto multiplier = 2;
    Io::Output(L"квадрат: " + to_wstring(Pow(number, multiplier++)));
    Io::Output(L"куб: " + to_wstring(Pow(number, multiplier++)));
    Io::Output(L"4 степень: " + to_wstring(Pow(number, multiplier)));
    Io::Output(L"");
}

auto Task1::Sum(int first, int second) -> int
{
    return first + second;
}

auto Task1::Subtraction(int first, int second) -> int
{
    return first - second;
}

auto Task1::Multy(int first, int second) -> int
{
    return first * second;
}

auto Task1::Division(int first, int second) -> float
{
    return (float) first / second;
}

auto Task1::Pow(int number, int multiplier) -> int
{
    return pow(number, multiplier);
}