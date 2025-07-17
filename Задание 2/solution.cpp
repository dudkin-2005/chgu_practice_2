#include <iostream>
#include <cmath>
#include <iomanip>  // для std::setprecision

using namespace std;

// Функция для вычисления расстояния от точки до начала координат
double distanceToOrigin(double x, double y) {
    return sqrt(x * x + y * y);
}

int main() {
    char repeat;

    do {
        // Ввод координат трёх точек
        double x1, y1, x2, y2, x3, y3;

        cout << "Введите координаты трёх точек (x1 y1 x2 y2 x3 y3): ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        // Вычисление расстояний
        double d1 = distanceToOrigin(x1, y1);
        double d2 = distanceToOrigin(x2, y2);
        double d3 = distanceToOrigin(x3, y3);

        // Вывод расстояний
        cout << fixed << setprecision(2);
        cout << "Расстояние от точки A до начала координат: " << d1 << endl;
        cout << "Расстояние от точки B до начала координат: " << d2 << endl;
        cout << "Расстояние от точки C до начала координат: " << d3 << endl;

        // Определение ближайшей точки
        if (d1 < d2 && d1 < d3) {
            cout << "Точка A ближе к началу координат." << endl;
        } else if (d2 < d1 && d2 < d3) {
            cout << "Точка B ближе к началу координат." << endl;
        } else if (d3 < d1 && d3 < d2) {
            cout << "Точка C ближе к началу координат." << endl;
        } else {
            cout << "Есть точки на одинаковом расстоянии от начала координат." << endl;
        }

        // Повтор программы
        cout << "Повторить вычисления? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "Программа завершена. До свидания!" << endl;

    return 0;
}