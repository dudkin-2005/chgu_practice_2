#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int hours = 40;            // �ᮢ ����⨩
    const int cost_per_hour = 100;   // �⮨����� ��
    const double teacher_share = 0.4; // ���� �९�����⥫�
    const double golden_goal = 20000; // "������ ���" � �㡫��

    int M;

    cout << "������ ���ᨬ��쭮� ������⢮ ��㤥�⮢ M: ";
    cin >> M;

    cout << fixed << setprecision(2);
    cout << "\n������ ��室� �९�����⥫�:\n";

    bool golden_reached = false;
    int min_students_for_gold = 0;

    for (int students = 1; students <= M; ++students) {
        double total_income = students * hours * cost_per_hour;
        double teacher_income = total_income * teacher_share;

        cout << "��㤥�⮢: " << students << " -> ��室 �९�����⥫�: " << teacher_income << " ��" << endl;

        if (!golden_reached && teacher_income >= golden_goal) {
            golden_reached = true;
            min_students_for_gold = students;
        }
    }

    if (golden_reached) {
        cout << "\n�९�����⥫� ����� ����������!" << endl;
        cout << "��� �⮣� �㦭� ������ ������ " << min_students_for_gold << " ��㤥�⮢." << endl;
    } else {
        cout << "\n� ᮦ������, �९�����⥫� �� ���⨣��� \"����⮩ ����\" (" << golden_goal << " ��) � " << M << " ��㤥�⠬�." << endl;
    }

    return 0;
}