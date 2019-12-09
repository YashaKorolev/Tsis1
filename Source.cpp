#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

const double goldenRatio = (1 + sqrt(5)) / 2; // "Золотое" число

// Рассматриваемая нами функция
double f(double x) {
	//tanh
	return cos(x) * tanh(x);
}

double passive_finder(double a, double b, double eps) {
	int i = 1;
	double minx = a;
	int N = 2 * (b - a) / eps;
	double step = (b - a) / ((double)N + 1);
	for (double x = a; x < b; x += step) {
		if (f(x) < f(minx)) {
			minx = x;
		}
		cout << i << fixed << std::setprecision(5) << ")x = " << x << fixed << setprecision(6) << " f(x) = " << f(x) << endl;
		i++;
	}
	cout << endl;
	std::cout << "N= " << N + 2<< " e=+-" << eps / 2 << "  x = " << minx << " f(x) = " << f(minx) << endl;
	return minx;
}


double gold_cut(double a1, double b1, double eps) {
	int N = 0;
	double a = a1, b = b1; // Концы отрезка
	double x1, x2; // Точки, делящие текущий отрезок в отношении золотого сечения
	int i = 1;
	x1 = b - (b - a) / goldenRatio;
	x2 = a + (b - a) / goldenRatio;
	cout << fixed << setprecision(6);
	while (2 * fabs(b - a) > eps) {


		if (f(x1) >= f(x2)) { // Условие для поиска минимума
			a = x1;
			x1 = x2;
			x2 = a + (b - a) / goldenRatio;
		}
		else {
			b = x2;
			x2 = x1;
			x1 = b - (b - a) / goldenRatio;
		}

		N++;
		cout << i << ")a=" << a << " b =" << b << "  lenght=" << b - a << "     x1=" << x1 << " f(x1)= " << f(x1) << "x2=" << x2 << "      f(x2)= " << f(x2) << endl;
		i++;
	} // Выполняем, пока не достигнем заданной точности
	cout << endl;
	cout << "N= " << N << "  a= " << a << "   b = " << b << "  lenght=" << b - a << "       x1=" << x1 << "   f(x1)= " << f(x1) << "  x2=" << x2 << " f(x2)= " << f(x2) << endl;
	return (a + b) / 2;
}



int main() {



	cout << "passive_finder " << endl;
	double xmin = passive_finder(1.5, 4, 0.1);//26
	cout << endl << endl;

	cout << "gold_cut " << endl;
	xmin = gold_cut(1.5, 4, 0.1);

	system("pause");
	return 0;
}
