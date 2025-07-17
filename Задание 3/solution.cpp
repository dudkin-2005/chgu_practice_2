#include <iostream>
#include <cstdlib>   // для rand и srand
#include <ctime>     // для time
#include <iomanip>   // для std::setprecision

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    char repeat;

    do {
        // Генерация случайной операции: '+' или '-'
        char op = (rand() % 2 == 0) ? '+' : '-';

        // Генерация случайных чисел (например, в диапазоне от 0 до 100)
        int a = rand() % 101;
        int b = rand() % 101;

        int correctAnswer;
        if (op == '+') {
            correctAnswer = a + b;
        } else {
            // Убедимся, что результат вычитания не отрицательный
            if (a < b) swap(a, b);
            correctAnswer = a - b;
        }

        int userAnswer;
        cout << "Сколько будет " << a << " " << op << " " << b << "? ";
        cin >> userAnswer;

        // Проверка ответа
        while (userAnswer != correctAnswer) {
            cout << "Неправильно! Попробуйте еще раз: ";
            cin >> userAnswer;
        }

        cout << "Правильно! Молодец!" << endl;

        // Предложить продолжить
        cout << "Хотите продолжить? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "Спасибо за тренировку! До новых встреч!" << endl;

    return 0;
}