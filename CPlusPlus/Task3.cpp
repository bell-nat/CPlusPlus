#include "Task3.h"
#include <format>
#include <sstream>

#include "Io.h"

using namespace std;

auto Task3::Query2() -> void
{
	auto digital = Io::GetInt(2);
	auto divisor = GetDivisor(digital);

	Io::Output(format
	(
		L"Наименьший натуральный делитель для числа {}, отличный от 1: {}",
		digital,
		divisor
	));

	const vector<int> divisors = GetDivisors(digital);
	const auto resultDivisors = Join(divisors, ", ");
	Io::Output(resultDivisors);

	bool isPrime = CheckPrime(digital);
	Io::Output(L"");	
}

auto Task3::Query3() -> void
{
	const auto digital = Io::GetInt(2);
	auto degree2 = GetDegree(digital, 2);
	Io::Output(format(L"{} - ближайшая степень двойки для числа: {}", degree2, digital));
	auto degree3 = GetDegree(digital, 3);
	Io::Output(format(L"{} - ближайшая степень двойки для числа: {}", degree3, digital));
	auto degree5 = GetDegree(digital, 5);
	Io::Output(format(L"{} - ближайшая степень двойки для числа: {}", degree5, digital));
}

auto Task3::GetDegree(int digital, int number) -> int
{
	const auto area = (log(digital) / log(number));
	const auto minDegree = static_cast<int>(area);
	const auto maxDegree = minDegree + 1;
	const auto min = static_cast<int>(pow(digital, minDegree));
	const auto max = static_cast<int>(pow(digital, maxDegree));
	const auto minDifference = digital - min;
	const auto maxDifference = max - digital;
	return minDifference < maxDifference ? minDegree : maxDegree;
}




auto Task3::GetDivisor(int digital) -> int
{
	auto divisor = 2;
	while(true)
	{
		if(digital % divisor == 0)
		{
			return divisor;
		}
		divisor++;
	}
}

auto Task3::GetDivisors(int digital) -> vector<int>
{
	vector<int> divisors;
	for (int divisor = 1; divisor <= digital; divisor++)
	{
		if (digital % divisor == 0)
		{
			divisors.push_back(divisor);
		}
	}

	return divisors;
}

auto Task3::CheckPrime(int digital) -> bool
{
	const vector<int> divisors = GetDivisors(digital);
	return divisors.size() > 2;
}

auto Task3::Join(const vector<int>& items, const string& sep) -> string
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