#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// �㭪�� ��� ���᫥��� ���頤� ��㣮�쭨��
double Square(double a, double b, double c) {
    // �஢�ઠ �� ����⢮����� ��㣮�쭨��
    if (a + b > c && a + c > b && b + c > a) {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    } else {
        return 0.0;
    }
}

int main() {
    cout << fixed << setprecision(2);
    cout << "������ ���頤�� ��㣮�쭨���:\n";

    for (int i = 1; i <= 10; ++i) {
        double a = i;
        double b = i + 1;
        double c = i + 2;

        double area = Square(a, b, c);

        if (area > 0) {
            cout << "��㣮�쭨� (" << a << ", " << b << ", " << c << "): ���頤� = " << area << endl;
        } else {
            cout << "��㣮�쭨� (" << a << ", " << b << ", " << c << ") �� �������." << endl;
        }
    }

    return 0;
}