#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;
void init(vector <double>& v, vector <double>& t, double& v0, double& dt, double g, double& t_max);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double v0, g,dt, t_max;
	g = 9.81;
	vector <double> v, t;
	init(v, t, v0, dt, g, t_max);

	if (v.empty()) {
		cout << "Данных нет.";
		return 0;
	}

	cout << "\nРезультаты:" << endl;
	cout << "Время (с)\tСкорость (м/с)" << endl;
	cout << "-----------------------" << endl;
	for (size_t i = 0; i < v.size(); i++) {
		cout << t[i] << "\t\t" << v[i] << endl;
	}
	return 0;
}


void init(vector <double>& v, vector <double>& t, double& v0, double& dt, double g, double& t_max)
{
	cout << "Введите начальную скорость (м/с): ";
	cin >> v0;
	while (v0 <= 0 or cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Введите положительное число: ";
		cin >> v0;
	}
	cout << "Введите шаг по времени (с): ";
	cin >> dt;
	while (dt <= 0 or cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Введите положительное число: ";
		cin >> dt;
	}
	cout << "Введите время полёта: ";
	cin >> t_max;
	while (t_max <= 0 or cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Введите положительное число: ";
		cin >> t_max;
	}

	int expected_size = (int)(t_max / dt) + 2; // +2 для запаса (начало и конец)
	v.reserve(expected_size);
	t.reserve(expected_size);

	for (double i = 0; i <= t_max; i += dt)
	{
		double  v_r = v0 - g * i;
		if (v_r <= 0)
		{
			continue;
		}
		v.push_back(v_r);
		t.push_back(i);
	}
}
