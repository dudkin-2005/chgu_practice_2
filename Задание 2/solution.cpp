#include <iostream>
#include <cmath>
#include <iomanip>  // ��� std::setprecision

using namespace std;

// �㭪�� ��� ���᫥��� ����ﭨ� �� �窨 �� ��砫� ���न���
double distanceToOrigin(double x, double y) {
    return sqrt(x * x + y * y);
}

int main() {
    char repeat;

    do {
        // ���� ���न��� ���� �祪
        double x1, y1, x2, y2, x3, y3;

        cout << "������ ���न���� ���� �祪 (x1 y1 x2 y2 x3 y3): ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        // ���᫥��� ����ﭨ�
        double d1 = distanceToOrigin(x1, y1);
        double d2 = distanceToOrigin(x2, y2);
        double d3 = distanceToOrigin(x3, y3);

        // �뢮� ����ﭨ�
        cout << fixed << setprecision(2);
        cout << "�����ﭨ� �� �窨 A �� ��砫� ���न���: " << d1 << endl;
        cout << "�����ﭨ� �� �窨 B �� ��砫� ���न���: " << d2 << endl;
        cout << "�����ﭨ� �� �窨 C �� ��砫� ���न���: " << d3 << endl;

        // ��।������ ������襩 �窨
        if (d1 < d2 && d1 < d3) {
            cout << "��窠 A ����� � ��砫� ���न���." << endl;
        } else if (d2 < d1 && d2 < d3) {
            cout << "��窠 B ����� � ��砫� ���न���." << endl;
        } else if (d3 < d1 && d3 < d2) {
            cout << "��窠 C ����� � ��砫� ���न���." << endl;
        } else {
            cout << "���� �窨 �� ���������� ����ﭨ� �� ��砫� ���न���." << endl;
        }

        // ����� �ணࠬ��
        cout << "������� ���᫥���? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "�ணࠬ�� �����襭�. �� ᢨ�����!" << endl;

    return 0;
}