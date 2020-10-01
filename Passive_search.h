#include "Fibonacci.h"


std::vector<std::pair<double, double>> PasValues(const double& a, const double& b, const double& quantity) {
    std::vector<std::pair<double, double>> values;
    size_t N = 1;
    double delta = (b - a) / (N + 1);
    double minX;
    while (delta > quantity) {
        std::vector<double> valuesY;
        delta = (b - a) / (N + 1);
        for (size_t k = 1; k <= N; ++k) {
            valuesY.push_back(f((b - a) / (N + 1) * k + a));
        }
        size_t kForMinY = std::min_element(valuesY.begin(), valuesY.end()) - valuesY.begin() + 1;
        minX = (b - a) / (N + 1) * kForMinY + a;
        values.push_back({ minX, delta });
        N++;
    }
    return values;
}

void PrintPasValues (const std::vector<std::pair<double, double>>& values)  {
    cout << "Расчет методом оптимально пассивоного поиска" << endl;
    cout << "|" << std::setw(23) << std::left << "Количество" << "|"
    << std::setw(28) << std::left << "Значение x" << "|" << endl;
    cout << "|" << std::setw(18) << std::left << "точек (N)" << "|"
    << std::setw(29) << std::left << "в минимуме" << "|" << endl;
    cout << std::string (36, '-') << endl;
    for (size_t i = 0; i < values.size(); i++){
        cout << "|" << std::setw(13) << i + 1 << "|" << std::setw(20)
        << std::to_string(values[i].first) + "+-" + std::to_string(values[i].second) << "|" << endl;
    }
    cout << std::string (36, '-') << endl;
}