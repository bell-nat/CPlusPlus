#include "Task1.h"
#include <iostream>
#include <cmath>

Task1::Task1()
{
}

auto Task1::Query1() -> void
{
    auto first = GetInt();
    auto second = GetInt();

    cout << "�����: " << Sum(first, second) << endl;
    cout << "��������: " << Subtraction(first, second) << endl;
    cout << "������������: " << Multy(first, second) << endl;
    cout << "�������: " << Division(first, second) << endl;
    cout << endl;
}

auto Task1::Query2() -> void
{
    auto number = GetInt();
    auto multiplier = 2;

    cout << "������� �����: " << Pow(number, multiplier++) << endl;
    cout << "��� �����: " << pow(number, multiplier++) << endl;
    cout << "�������� ������� �����: " << pow(number, multiplier) << endl;
    cout << endl;
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

auto Task1::GetInt() -> int
{
    auto numberSource = InputString();
    return ConvertToInt(numberSource);
}

auto Task1::InputString() -> string
{
    string source;
    cout << "������� �����: ";
    cin >> source;
    cout << endl << "�� �����: " << source << endl << endl;
    return source;
}

auto Task1::ConvertToInt(string source) -> int
{
    try
    {
        return stoi(source);
    }
    catch (const exception&)
    {
        throw new exception("������ ����������� � �����!");
    }
}