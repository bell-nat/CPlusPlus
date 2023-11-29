#pragma once
#include <string>
#include <vector>

using namespace std;

class Extension
{
public:
	Extension();
	const static wstring Endl;
	auto static Join(const vector<int>& items, const string& sep) -> string;
};
