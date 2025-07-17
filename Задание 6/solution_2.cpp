#include <iostream>
#include <cmath>
using namespace std;

// Ввод массива
void inputArray(double arr[], int size) {
    cout << "Введите координаты точек на прямой:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Точка " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Вывод массива
void outputArray(double arr[], int size) {
    cout << "Массив точек:\n";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Центр тяжести
double centerOfMass(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return sum / size;
}

// Найти наиболее удалённую точку
int farthestFromCenter(double arr[], int size, double center) {
    int index = 0;
    double maxDist = abs(arr[0] - center);
    for (int i = 1; i < size; ++i) {
        double dist = abs(arr[i] - center);
        if (dist > maxDist) {
            maxDist = dist;
            index = i;
        }
    }
    return index;
}

// Удалить элемент по индексу
void removeElement(double arr[], int& size, int index) {
    for (int i = index; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    --size;
}

int main() {
    int size = 5;
    double points[size];

    inputArray(points, size);
    outputArray(points, size);

    double center = centerOfMass(points, size);
    cout << "Центр тяжести: " << center << endl;

    int farIndex = farthestFromCenter(points, size, center);
    cout << "Наиболее удалённая точка: " << points[farIndex] << " (индекс " << farIndex << ")" << endl;

    removeElement(points, size, farIndex);
    cout << "Массив после удаления точки:\n";
    outputArray(points, size);

    return 0;
}