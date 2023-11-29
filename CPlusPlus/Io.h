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
	static auto GetDouble() -> double;
	static auto Output(const wstring& text, bool isNewLine = true) -> void;
	static auto Output(const string& source, bool isNewLine = true) -> void;
private:
	static auto Input() -> wstring;
	static auto TryParseInt(const wstring& source, int& result, int min = NULL, int max = NULL) -> bool;
	static auto TryParseDouble(const wstring& source, double& result) -> bool;
};