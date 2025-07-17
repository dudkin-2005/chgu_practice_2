#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Функция для ввода данных о молоке
void inputMilkProduction(double milk[], int size) {
    cout << "Введите количество молока, литров, которое дала каждая корова:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Корова №" << i + 1 << ": ";
        cin >> milk[i];
        while (cin.fail() || milk[i] < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Введите неотрицательное число: ";
            cin >> milk[i];
        }
    }
}

// Функция для вывода результатов
void outputMilkProduction(const double milk[], int size) {
    cout << "\nРезультаты по коровам:\n";
    for (int i = 0; i < size; ++i)
        cout << "Корова №" << i + 1 << " дала " << fixed << setprecision(2) << milk[i] << " литров молока\n";
}

// Функция для подсчёта общего количества молока
double totalMilk(const double milk[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += milk[i];
    return sum;
}

// Функция для поиска коровы с максимальным надоем
int bestCow(const double milk[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (milk[i] > milk[index])
            index = i;
    return index;
}

// Функция для поиска коровы с минимальным надоем
int worstCow(const double milk[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (milk[i] < milk[index])
            index = i;
    return index;
}

int main() {
    const int numCows = 10;
    double milk[numCows];

    inputMilkProduction(milk, numCows);
    outputMilkProduction(milk, numCows);

    double total = totalMilk(milk, numCows);
    int best = bestCow(milk, numCows);
    int worst = worstCow(milk, numCows);

    cout << "\nВсего молока получено за день: " << fixed << setprecision(2) << total << " литров" << endl;
    cout << "Отличилась корова №" << best + 1 << ", надоившая " << milk[best] << " литров" << endl;
    cout << "Меньше всех дала молока корова №" << worst + 1 << ", надоившая " << milk[worst] << " литров" << endl;

    return 0;
}