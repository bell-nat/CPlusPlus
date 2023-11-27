﻿// CPlusPlus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

#include "Extension.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

using namespace std;

int main()
{
    Io::SetLanguage();

    const auto task1 = new Task1();
    task1->Query1();
    task1->Query2();
    delete task1;

    wcout << Extension::Endl;

    const auto task2 = new Task2();
    task2->Start();
    delete task2;

    wcout << Extension::Endl;

    const auto task3 = new Task3();
    task3->Start();
    delete task3;

    wcout << Extension::Endl;

    const auto task4 = new Task4();
    task4->Start();
    delete task4;
}