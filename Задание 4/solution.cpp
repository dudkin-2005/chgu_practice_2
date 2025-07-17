#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int hours = 40;            // часов занятий
    const int cost_per_hour = 100;   // стоимость часа
    const double teacher_share = 0.4; // доля преподавателя
    const double golden_goal = 20000; // "золотая гора" в рублях

    int M;

    cout << "Введите максимальное количество студентов M: ";
    cin >> M;

    cout << fixed << setprecision(2);
    cout << "\nРасчёт дохода преподавателя:\n";

    bool golden_reached = false;
    int min_students_for_gold = 0;

    for (int students = 1; students <= M; ++students) {
        double total_income = students * hours * cost_per_hour;
        double teacher_income = total_income * teacher_share;

        cout << "Студентов: " << students << " -> Доход преподавателя: " << teacher_income << " руб" << endl;

        if (!golden_reached && teacher_income >= golden_goal) {
            golden_reached = true;
            min_students_for_gold = students;
        }
    }

    if (golden_reached) {
        cout << "\nПреподаватель может озолотиться!" << endl;
        cout << "Для этого нужно обучить минимум " << min_students_for_gold << " студентов." << endl;
    } else {
        cout << "\nК сожалению, преподаватель не достигнет \"золотой горы\" (" << golden_goal << " руб) с " << M << " студентами." << endl;
    }

    return 0;
}