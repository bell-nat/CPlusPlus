#include "Task1.h"
#include "Io.h"
#include <iostream>
#include <cmath>

#include "Extension.h"

Task1::Task1() { _io = new Io(); }

Task1::~Task1() { delete _io; }

auto Task1::Query1() -> void
{
	const auto first = _io->GetInt();
	const auto second = _io->GetInt();

    wcout << L"Сумма: " << Sum(first, second) << Extension::Endl;
    wcout << L"Разность: " << Subtraction(first, second) << Extension::Endl;
    wcout << L"Произведение: " << Multy(first, second) << Extension::Endl;
    wcout << L"Частное: " << Division(first, second) << Extension::Endl;
    wcout << Extension::Endl;
}

auto Task1::Query2() -> void
{
	const auto number = _io->GetInt();
    auto multiplier = 2;

    wcout << L"квадрат: " << Pow(number, multiplier++) << Extension::Endl;
    wcout << L"куб: " << pow(number, multiplier++) << Extension::Endl;
    wcout << L"4 степень: " << pow(number, multiplier) << Extension::Endl;
    wcout << Extension::Endl;
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