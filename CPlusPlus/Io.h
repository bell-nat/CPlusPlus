#pragma once
#include <string>

using namespace std;

class Io
{
public:
	Io();
	auto GetString()->string;
	auto GetInt(const int min = NULL, const int max = NULL) -> int;
private:
	auto Input() -> string;
	auto ConvertToInt(const string& source, int min = NULL, int max = NULL) -> int;
};