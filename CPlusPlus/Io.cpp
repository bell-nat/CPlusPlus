#include "Io.h"
#include "Extension.h"
#include <iostream>

Io::Io()
= default;

auto Io::GetString() -> string
{
    return Input();
}

auto Io::GetInt(const int min, const int max) -> int
{
    const auto source = Input();
    return ConvertToInt(source, min, max);
}


auto Io::Input() -> string
{
    string source;
    cout << "Введите число: ";
    cin >> source;
    cout << "Вы ввели: " << source << Extension::Endl;
    return source;
}

auto Io::ConvertToInt(const string& source, const int min, const int max) -> int
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
            cout << "Повторите ввод" << Extension::Endl;
        }
        catch (const exception&)
        {
            cout << "Не число!" << "Повторите ввод" << Extension::Endl;
        }
    } while (true);   
}