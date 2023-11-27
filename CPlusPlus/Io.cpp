#include "Io.h"

#include <corecrt_io.h>
#include <fcntl.h>

#include "Extension.h"
#include <iostream>

Io::Io()
= default;

auto Io::SetLanguage() -> void
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
    const auto source = Input();
    return ConvertToInt(source, min, max);
}

auto Io::Output(wstring text) -> void
{   
    wcout << text << Extension::Endl;

}


auto Io::Input() -> wstring
{
    wstring source;
    wcout << L"Введите число: ";
    wcin >> source;
    wcout << L"Вы ввели: " << source << Extension::Endl;
    return source;
}

auto Io::ConvertToInt(const wstring& source, const int min, const int max) -> int
{
    do
    {
        try
        {
            const auto digital = stoi(source);
	        if ((min == NULL || digital >= min) && (max == NULL || digital <= max))
            {
                return digital;
            }
            wcout << "Повторите ввод" << Extension::Endl;
        }
        catch (const exception&)
        {
            wcout << "Не число!" << "Повторите ввод" << Extension::Endl;
        }
    } while (true);   
}