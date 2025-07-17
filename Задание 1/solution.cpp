#include <iostream>
#include <cmath>
#include <iomanip>  // для std::setprecision

int main() {
    double x1, y1; // координаты левой верхней вершины
    double x2, y2; // координаты правой нижней вершины

    // Ввод координат
    std::cout << "Введите координаты левой верхней вершины (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Введите координаты правой нижней вершины (x2 y2): ";
    std::cin >> x2 >> y2;

    // Вычисление длины стороны квадрата
    double side = std::abs(x2 - x1); // можно также взять std::abs(y2 - y1)

    // Вычисление длины диагонали
    double diagonal = side * std::sqrt(2);

    // Координаты центра квадрата (точка пересечения диагоналей)
    double center_x = (x1 + x2) / 2.0;
    double center_y = (y1 + y2) / 2.0;

    // Вывод результатов
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Длина стороны квадрата: " << side << std::endl;
    std::cout << "Длина диагонали квадрата: " << diagonal << std::endl;
    std::cout << "Координаты точки пересечения диагоналей: (" 
              << center_x << ", " << center_y << ")" << std::endl;

    return 0;
}