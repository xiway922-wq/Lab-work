#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double TaylorSum(double x, int k);
double ExactValue(double x);

int main()
{
	setlocale(LC_ALL, "RU");
	double x;
	cout << "Введите x (-1 < x < 1): ";
	cin >> x;
	if (x <= -1 || x >= 1)
	{
		cout << "x должен принадлежать интервалу (-1, 1)";
		return 1;
	}

	int k;
	cout << "Введите k (k>1): ";
	cin >> k;
	if (k <= 1)
	{
		cout << "k должно быть целым числом больше 1";
		return 2;
	}

	double taylor_sum = TaylorSum(x, k);
	double exact_sum = ExactValue(x);

	// Определяет кол-во знаков после запятой
	cout << fixed << setprecision(k);

	cout << "Сумма по ряду Тейлора: " << taylor_sum << endl;
	cout << "Сумма, вычисленная стандартными функциями: " << exact_sum << endl;
	cout << "Разница:" << fabs(taylor_sum - exact_sum);

	return 0;

}

double TaylorSum(double x, int k)
{
	double taylor_sum = 0.0;
	double term;
	double n = 0.0;
	do {
		term = pow(-1, n) * (((n + 1) * (n + 2)) / 2) * pow(x, n);
		taylor_sum += term;
		++n;
	} while (fabs(term) > pow(10, -k));

	return taylor_sum;
}

double ExactValue(double x)
{
	double exact_sum = 1 / pow(1 + x, 3);
	return exact_sum;
}
