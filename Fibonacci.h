#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::endl;

double f (const double& x){
    return (pow(x ,2) * sin(x));
}


int64_t Fib( const size_t &n )
{
    if (n < 1) return 0;
    int64_t f1 = 0 , f2 = 1, fn = 0;
    for ( size_t  i = 1; i < n; ++i )
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}


std::vector<double> Fib_values(double& a, double& b, size_t n)
{
    std::vector<double> values;
    double  x1 = a + (b - a) * Fib(n) / Fib(n + 2);
    double  x2 = a +  b - x1;
    double  y1 = f(x1);
    double  y2 = f(x2);
    while (n--) {
        if (y1 > y2) {
            a = x1;
            x1 = x2;
            x2 = b - (x1 - a);
            y1 = y2;
            y2 = f(x2);
            values.push_back(x2);
        }
        else {
            b = x2;
            x2 = x1;
            x1 = a + (b - x2);
            y2 = y1;
            y1 = f(x1);
            values.push_back(x1);
        }
    }
    return values;
}

void PrintValues (const std::vector<double>& values){
    cout << "Расчет методом Фибоначчи" << endl;
    cout << "|" << std::setw(23) << std::left << "Количество" << "|"
    << std::setw(22) << std::left << "Значение y" << "|" << endl;
    cout << "|" << std::setw(18) << std::left << "точек (N)" << "|"
    << std::string(14,' ') << "|" << endl;
    cout << std::string (30, '-') << endl;
    for (size_t i = 0; i < values.size(); i++){
        cout << "|" << std::setw(13) << i + 1 << "|" << std::setw(14) << std::setprecision(11) << values[i] << "|" << endl;
    }
    cout << std::string (30, '-') << endl;
    cout << "Минимальное значение функции в точке: " << values[values.size()-1] << endl;
}
