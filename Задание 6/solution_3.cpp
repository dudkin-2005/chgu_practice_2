#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Генерация случайного массива
void generateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 201 - 100; // от -100 до 100
}

// Фильтрация массива по знаку
int filterArray(int* source, int srcSize, int*& result, int sign) {
    int count = 0;
    for (int i = 0; i < srcSize; ++i)
        if ((sign > 0 && source[i] > 0) || (sign < 0 && source[i] < 0))
            ++count;

    result = new int[count];
    int idx = 0;
    for (int i = 0; i < srcSize; ++i)
        if ((sign > 0 && source[i] > 0) || (sign < 0 && source[i] < 0))
            result[idx++] = source[i];

    return count;
}

int main() {
    srand(time(0));

    const int srcSize = 10;
    int source[srcSize];
    generateArray(source, srcSize);

    cout << "Исходный массив:\n";
    for (int i = 0; i < srcSize; ++i)
        cout << source[i] << " ";
    cout << endl;

    int* positive = nullptr;
    int positiveSize = filterArray(source, srcSize, positive, 1);

    cout << "Положительные элементы:\n";
    for (int i = 0; i < positiveSize; ++i)
        cout << positive[i] << " ";
    cout << endl;
    delete[] positive;

    int* negative = nullptr;
    int negativeSize = filterArray(source, srcSize, negative, -1);

    cout << "Отрицательные элементы:\n";
    for (int i = 0; i < negativeSize; ++i)
        cout << negative[i] << " ";
    cout << endl;
    delete[] negative;

    return 0;
}