#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;
void init(vector <double>& times, vector <double>& height, double dt, double g, double v);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << fixed << setprecision(2);

	double dt, g, v;
	dt = 1; g = 9.8; v = 50;
	vector <double> times; vector <double> height;
	init(times, height, dt, g, v);

	if (height.empty()) {
		cout << "Данных нет.";
		return 0;
	}
	auto max = max_element(height.begin(), height.end());
	auto ind_max = distance(height.begin(), max);

	cout << "Results: max height = " << *max << "m, time = " << times[ind_max] << " s";



	return 0;
}

void init(vector <double>& times, vector <double>& height, double dt, double g, double v)
{
	double total_time = 2 * v / g;
	times.reserve((int)(v * 2 / g / dt)); height.reserve((int)(v * 2 / g / dt));
	for (double t = 0; t <= total_time; t += dt)
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
}