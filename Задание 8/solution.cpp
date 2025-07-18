#include <iostream>
using namespace std;

// Функция проверяет, упорядочен ли массив по возрастанию
bool isAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

// Функция выводит строку матрицы и результат проверки
void printRowAndResult(int row[], int size, int rowIndex) {
    cout << "Строка " << rowIndex + 1 << ": ";
    for (int i = 0; i < size; ++i)
        cout << row[i] << " ";
    
    if (isAscending(row, size))
        cout << "-> упорядочена по возрастанию";
    else
        cout << "-> НЕ упорядочена по возрастанию";
    
    cout << endl;
}

int main() {
    int n, m;

    cout << "Введите размер матрицы (n m): ";
    cin >> n >> m;

    // Динамическое выделение памяти под матрицу
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[m];

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы по строкам:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
    }

    // Проверка и вывод
    cout << "\nАнализ матрицы:\n";
    for (int i = 0; i < n; ++i)
        printRowAndResult(matrix[i], m, i);

    // Освобождение памяти
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}