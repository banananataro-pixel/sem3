#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << fixed << setprecision(2);

	double dt, g, v;
	dt = 1; g = 9.8; v = 50;
	vector <double> times; vector <double> height;
	times.reserve((int)(v * 2 / g / dt)); height.reserve((int)(v * 2 / g / dt));

	for (double t = 0; t <= 1000; t+=dt)
	{
		double h = v * t - 0.5 * g * t * t;

		if (h > 0)
		{
			times.push_back(t); height.push_back(h);
		}
		else
		{
			continue;
		}

	}
	cout << "+------------------------------+" << endl;
	cout << "|   Таблица полета тела        |" << endl;
	cout << "+----------+-------------------+" << endl;
	cout << "|  Время   |      Высота       |" << endl;
	cout << "|   (с)    |       (м)         |" << endl;
	cout << "+----------+-------------------+" << endl;

	for (size_t i = 0; i < times.size(); i++) {
		cout << "| " << setw(8) << times[i] << " | " << setw(15) << height[i] << "   |" << endl;
	}

	cout << "+----------+-------------------+" << endl;


	return 0;
}