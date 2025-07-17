#include <iostream>
using namespace std;

// Проверяет, упорядочен ли массив по возрастанию
bool isAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

// Проверяет, упорядочен ли массив по убыванию
bool isDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        if (arr[i] < arr[i + 1])
            return false;
    return true;
}

// Определяет тип упорядоченности
int checkOrder(int arr[], int size) {
    if (isAscending(arr, size)) return 1;
    if (isDescending(arr, size)) return -1;
    return 0;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = checkOrder(arr, size);

    cout << "Массив: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    if (result == 1)
        cout << "Массив упорядочен по возрастанию." << endl;
    else if (result == -1)
        cout << "Массив упорядочен по убыванию." << endl;
    else
        cout << "Массив не упорядочен." << endl;

    return 0;
}