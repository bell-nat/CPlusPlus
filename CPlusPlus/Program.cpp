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
    const auto task2 = new Task2();
    const auto task3 = new Task3();
    const auto task4 = new Task4();

    auto isRepeat = true;
    do
    {
        Io::Output(L"\t1. Пользователь вводит два числа.\r\nОба числа не являются нулём.\r\nВывести их сумму, разность, произведение, частное.\r\n");
        Io::Output(L"\t2. Пользователь вводит число.\r\nВывести на экран квадрат, куб и четвёртую степень этого числа.\r\n");
        Io::Output(L"\t3. Написать программу, которая на вход получает три действительных числа – длины сторон треугольника,\r\n"
			L"а в качестве выходных значений возвращает пользователю ответ:\r\n" 
			L"«равнобедренный»\r\n" 
			L"«равносторонний»\r\n" 
			L"«прямоугольный»\r\n" 
			L"«произвольный»\r\n" 
			L"«вырожденный»\r\n" 
			L"«не является треугольником»\r\n" 
			L"«некорректные входные данные»");
        Io::Output(L"\t4. Написать программу, входными значениями которой являются номер дня с начала месяца,\r\n"
			L"номер месяца и тип года (0 – невисокосный, 1 – високосный),\r\n"
			L"а единственным выходным значением программы является номер дня с начала года.");
        Io::Output(L"\t5. Дано целое число, не меньшее двух.\r\n"
			L"Вывести:\r\n"
			L"1) его наименьший натуральный делитель, отличный от 1;\r\n"
			L"2) список всех натуральных делителей данного числа;\r\n"
			L"3) «простое», если число является таковым и «не является простым» иначе.");
        Io::Output(L"\t6. Дано натуральное число N.\r\n"
			L"Вывести ближайшую к этому числу степень двойки, тройки и пятёрки.");
        Io::Output(L"\t7. Поместить элементы массива X в начало массива Y в обратном порядке,\r\n"
			L"исключив элементы, превосходящие по абсолютной величине вводимое значение R.");
        Io::Output(L"\t8. Выполнить циклический сдвиг элементов массива Х(N), N≤10,\r\n"
			L"в результате которого значение последнего элемента должно оказаться на месте первого,\r\n"
			L"а остальные – сдвинутыми на одну позицию в сторону увеличения индекса.");
        Io::Output(L"Для выхода введите 0."); 
        Io::Output(Extension::Endl); 
        Io::Output(L"Введите № задания : ", false);

        switch (Io::GetInt(0, 8))
        {
			case 1:
                task1->Query1();
				break;                
            case 2:
                task1->Query2();
                break;
            case 3:
                task2->Query2();
                break;
            case 4:
                task2->Query3();
                break;
            case 5:
                task3->Query2();
                break;
            case 6:
                task3->Query3();
                break;
            case 7:
                task4->Query1();
                break;
            case 8:
                task4->Query2();
                break;
            default:
                isRepeat = false;
                break;                
        }
        if(isRepeat)
        {
            Io::Output(L"Для продолжения нажмите с(С)");
            auto line = Io::GetString();
            while(line != L"C" && line != L"С" && line != L"c" && line != L"с")
            {
                line = Io::GetString();
            }
        }
    } while (isRepeat);

    delete task1;
    delete task2;
    delete task3;
    delete task4;
}