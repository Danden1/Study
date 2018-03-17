#include <iostream>
using namespace std;

double add(double x, double y);		
double sub(double x, double y);		

double calculate(double x, double y, double (*pf)(double, double));

int main()
{
	double (*pf[2]) (double, double) = {add, sub};
	double x, y;
	double array[2];

	cout << "x와 y를 입력(끝내려면 q를 입력): ";
	while (cin >> x && cin >> y)
	{
		for (int i = 0; i < 2; i++)
			array[i] = calculate(x, y, pf[i]);
		
		cout << "x + y = " << array[0] << endl;
		cout << "x - y = " << array[1] << endl;

		cout << endl;
		
		cout << "x와 y를 입력(끝내려면 q를 입력): ";
	}
	return 0;
}

double add(double x, double y)
{
	return x + y;
}

double sub(double x, double y)
{
	return x - y;
}

