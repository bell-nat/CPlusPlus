#pragma once
#include <string>

using namespace std;

class Io
{
public:
	Io();
	static auto SetLanguage() -> void;
	auto GetString()-> wstring;
	auto GetInt(const int min = NULL, const int max = NULL) -> int;
	auto Output(wstring text) -> void;
private:
	auto Input() -> wstring;
	auto ConvertToInt(const wstring& source, int min = NULL, int max = NULL) -> int;
};