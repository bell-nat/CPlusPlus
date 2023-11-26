// CPlusPlus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    auto task1 = new Task1();
    task1->Query1();
    task1->Query2();
    delete task1;

    cout << endl;

    auto task2 = new Task2();
    task2->Start();
    delete task2;

    cout << endl;

    auto task3 = new Task3();
    task3->Start();
    delete task3;

    cout << endl;

    auto task4 = new Task4();
    task4->Start();
    delete task4;
}