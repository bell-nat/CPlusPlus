#include "Extension.h"

#include <sstream>
#include <vector>

using namespace std;

Extension::Extension()
= default;

const wstring Extension::Endl = L"\r\n";

auto Extension::Join(const vector<int>& items, const string& sep) -> string
{
	ostringstream oss;
	const auto last = items.end() - 1;
	// Iterate through the first to penultimate items appending the separator.
	for (typename vector<int>::const_iterator p = items.begin(); p != last; ++p)
	{
		oss << *p << sep;
	}
	// Join the last item without a separator.
	oss << *last;
	return oss.str();
}