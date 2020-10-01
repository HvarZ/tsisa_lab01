#include "Fibonacci.h"
#include "Passive_search.h"

double N = 29;
double QUANTITY = 0.05;
double LEFT_EDGE = 9.0;
double RIGHT_EDGE = 12.0;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Вариант 15" << endl;
    cout << "Функция: y = x^2 * sin(x)" << endl;
    cout << "Интервал: [9, 12]" << endl << endl;

    std::vector<std::pair<double,double>> values = PasValues(LEFT_EDGE, RIGHT_EDGE, QUANTITY);
    PrintPasValues(values);
    cout << endl;

    std::vector<double> Fibvalues  = Fib_values(LEFT_EDGE, RIGHT_EDGE, N);
    PrintValues(Fibvalues);
}
