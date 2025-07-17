#include <iostream>
#include <cstdlib>   // ��� rand � srand
#include <ctime>     // ��� time
#include <iomanip>   // ��� std::setprecision

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // ���樠������ ������� ��砩��� �ᥫ

    char repeat;

    do {
        // ������� ��砩��� ����樨: '+' ��� '-'
        char op = (rand() % 2 == 0) ? '+' : '-';

        // ������� ��砩��� �ᥫ (���ਬ��, � ��������� �� 0 �� 100)
        int a = rand() % 101;
        int b = rand() % 101;

        int correctAnswer;
        if (op == '+') {
            correctAnswer = a + b;
        } else {
            // ��������, �� १���� ���⠭�� �� ����⥫��
            if (a < b) swap(a, b);
            correctAnswer = a - b;
        }

        int userAnswer;
        cout << "����쪮 �㤥� " << a << " " << op << " " << b << "? ";
        cin >> userAnswer;

        // �஢�ઠ �⢥�
        while (userAnswer != correctAnswer) {
            cout << "���ࠢ��쭮! ���஡�� �� ࠧ: ";
            cin >> userAnswer;
        }

        cout << "�ࠢ��쭮! �������!" << endl;

        // �।������ �த������
        cout << "���� �த������? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "���ᨡ� �� �७�஢��! �� ����� �����!" << endl;

    return 0;
}