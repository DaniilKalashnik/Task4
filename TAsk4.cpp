// TAsk4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include <locale>
#include <iostream>
#include <math.h>
using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

double sumN(double x, int n, double& lastx)
{
	lastx = x;
	double sum = lastx;
	for (int i = 1; i < n; ++i)
	{
		double r; // отношение i слагаемлого к (i - 1)
		r = -x * x / (2 * i) / (2 * i + 1); // значение r
		lastx *= r;
		sum += lastx;
	}
	return sum;
}

double sumE(double x, double E, int& n)
{
	double lastx;

	lastx = x;
	double sum = lastx;
	for (n = 1; fabs(lastx) > E; ++n)
	{
		double r;
		r = -x * x / (2 * n) / (2 * n + 1); ;
		lastx *= r;
		sum += lastx;
	}
	return sum;
}
int main()
{
	setlocale(LC_ALL, "rus");
	char again;
	do {
		double x; // значение аргумента
		double func; // точное значение функции
		double sum; // частичная сумма
		int n; // число слагамых в частичной сумме

		cout << "          Задание 1" << endl;
		cout << "---------------------------------" << endl;
		cout << "Введите значение аргумента: ";
		cin >> x;
		cout << endl;
		cout << "Введите количество слагаемых: ";
		cin >> n;
		cout << endl;
		func = 1 / ((1 + x) * (1 + x));
		double lastx;
		sum = sumN(x, n, lastx);
		cout << "Точное значение функции равно: " << func << endl;
		cout << "Частичная сумма:" << sum << endl;
		cout << "Абсолютная погрешность: " << fabs(func - sum) << endl;
		cout << "Последнее слагаемое -> " << lastx << endl;
		if (fabs(func - sum) > lastx) cout << "Абсолютная погрешность больше последнего слагаемого";
		if (fabs(func - sum) == lastx) cout << " Абсолютная погрешность равна последнему слагаемому";
		if (fabs(func - sum) < lastx) cout << "Абсолютная погрешность меньше последнего слагаемого";
		cout << endl;
		cout << "           Задание 2" << endl;
		cout << "---------------------------------" << endl;
		double E;
		cout << "Введите значение аргумента: ";
		cin >> x;
		cout << endl;
		cout << "Укажите требуемую точность вычислений: ";
		cin >> E;
		cout << endl;
		func = 1 / ((1 + x) * (1 + x));
		sum = sumE(x, E, n);
		cout << "Точное значение функции равно " << func << endl;
		cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
		sum = sumE(x, E / 10, n);
		cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
		cout << "Если хотите повторить программу введите Y, для выхода из программы введите N" << endl; // запуск программы повторно
		cin >> again; //Вводим переменнную, отвечающую за меню
	} 
	while ((again == 'Y') || (again == 'y')); //Проверям продолжаем или нет
	system("pause");
	return 0;
}
