#pragma once
#include <codecvt>
#include <string>

using namespace std;

class Io
{	
public:
	Io();
	static auto SetLocale() -> void;
	static auto GetString()-> wstring;
	static auto GetInt(int min = NULL, int max = NULL) -> int;
	static auto Output(const wstring& text) -> void;
	static auto Output(const string& source) -> void;
private:
	static auto Input() -> wstring;
	static auto ConvertToInt(const wstring& source, int min = NULL, int max = NULL) -> int;
};