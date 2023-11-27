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
        if(TryParse(Input(), result, min, max))
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

auto Io::TryParse(const wstring& source, int& result, const int min, const int max) -> bool
{
    do
    {
        try
        {
            const auto digital = stoi(source);
            if ((min == NULL || digital >= min) && (max == NULL || digital <= max))
            {
                result = digital;
                return true;
            }
            return false;
        }
        catch (const exception&)
        {
            wcout << L"Не число! " << L"Повторите ввод" << Extension::Endl;
            return false;
        }
    } while (true);
}