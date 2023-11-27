// Program.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fcntl.h>

#include "Extension.h"
#include "Io.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

using namespace std;

int main()
{
    Io::SetLocale();

    const auto task1 = new Task1();
    task1->Query1();
    task1->Query2();
    delete task1;

    wcout << Extension::Endl;

    const auto task2 = new Task2();
    task2->Query2();
    task2->Query3();
    delete task2;

    wcout << Extension::Endl;

    const auto task3 = new Task3();
    task3->Query2();
    task3->Query3();
    delete task3;

    wcout << Extension::Endl;

    const auto task4 = new Task4();
    task4->Query1();
    task4->Query2();
    delete task4;
}