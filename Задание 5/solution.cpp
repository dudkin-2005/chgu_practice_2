#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления площади треугольника
double Square(double a, double b, double c) {
    // Проверка на существование треугольника
    if (a + b > c && a + c > b && b + c > a) {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    } else {
        return 0.0;
    }
}

int main() {
    cout << fixed << setprecision(2);
    cout << "Расчёт площадей треугольников:\n";

    for (int i = 1; i <= 10; ++i) {
        double a = i;
        double b = i + 1;
        double c = i + 2;

        double area = Square(a, b, c);

        if (area > 0) {
            cout << "Треугольник (" << a << ", " << b << ", " << c << "): площадь = " << area << endl;
        } else {
            cout << "Треугольник (" << a << ", " << b << ", " << c << ") не существует." << endl;
        }
    }

    return 0;
}