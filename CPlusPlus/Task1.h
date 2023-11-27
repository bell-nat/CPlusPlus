#pragma once

class Task1
{
public:
	Task1();
	~Task1();
	auto Query1() -> void;
	auto Query2() -> void;
private:
	auto Sum(int first, int second) -> int;
	auto Subtraction(int first, int second) -> int;
	auto Multiplication(int first, int second) -> int;
	auto Division(int first, int second) -> float;
	auto Pow(int number, int multiplier) -> int;
};