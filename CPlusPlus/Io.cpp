#include "Io.h"
#include <corecrt_io.h>
#include <fcntl.h>
#include "Extension.h"
#include <iostream>

Io::Io()
= default;

auto Io::SetLocale() -> void
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
}

auto Io::GetString() -> wstring
{
    return Input();
}

auto Io::GetInt(const int min, const int max) -> int
{
    int result;
    do
    {        
        if(TryParseInt(Input(), result, min, max))
        {
            return result;
        }
        Output(L"Значение находится за пределами разрешенного диапазона, повторите ввод");        
    } while (true);
}

auto Io::GetDouble() -> double
{
    double result;
    do
    {
        if (TryParseDouble(Input(), result))
        {
            return result;
        }
        Output(L"Повторите ввод");
    } while (true);
}


auto Io::Output(const wstring& text) -> void
{   
    wcout << text << Extension::Endl;
}

auto Io::Output(const string& source) -> void
{
	const wstring text(source.begin(), source.end());
    wcout << text << Extension::Endl;
}


auto Io::Input() -> wstring
{
    wstring source;
    Output(L"Введите число: ");
    wcin >> source;
    Output(L"Вы ввели: " + source);
    return source;
}

auto Io::TryParseInt(const wstring& source, int& result, const int min, const int max) -> bool
{
    try
    {
        const auto digital = stoi(source);
        if ((min == NULL || digital >= min) && (max == NULL || digital <= max))
        {
            result = digital;
            return true;
        }        
    }
    catch (const exception&)
    {
        Output(L"Не число! " + source + L"Повторите ввод");
    }
    return false;
}

auto Io::TryParseDouble(const wstring& source, double& result) -> bool
{
    auto isParse = false;
    try
    {
        result = stod(source);
        isParse = true;
    }
    catch (const exception&)
    {
        Output(L"Не число! " + source + L"Повторите ввод");
    }
    return isParse;
}