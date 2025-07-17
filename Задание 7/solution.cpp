#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// �㭪�� ��� ����� ������ � ������
void inputMilkProduction(double milk[], int size) {
    cout << "������ ������⢮ ������, ���஢, ���஥ ���� ������ ��஢�:\n";
    for (int i = 0; i < size; ++i) {
        cout << "��஢� �" << i + 1 << ": ";
        cin >> milk[i];
        while (cin.fail() || milk[i] < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�訡�� �����. ������ ������⥫쭮� �᫮: ";
            cin >> milk[i];
        }
    }
}

// �㭪�� ��� �뢮�� १���⮢
void outputMilkProduction(const double milk[], int size) {
    cout << "\n�������� �� ��஢��:\n";
    for (int i = 0; i < size; ++i)
        cout << "��஢� �" << i + 1 << " ���� " << fixed << setprecision(2) << milk[i] << " ���஢ ������\n";
}

// �㭪�� ��� ������� ��饣� ������⢠ ������
double totalMilk(const double milk[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += milk[i];
    return sum;
}

// �㭪�� ��� ���᪠ ��஢� � ���ᨬ���� ������
int bestCow(const double milk[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (milk[i] > milk[index])
            index = i;
    return index;
}

// �㭪�� ��� ���᪠ ��஢� � ��������� ������
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

    cout << "\n�ᥣ� ������ ����祭� �� ����: " << fixed << setprecision(2) << total << " ���஢" << endl;
    cout << "�⫨稫��� ��஢� �" << best + 1 << ", �������� " << milk[best] << " ���஢" << endl;
    cout << "����� ��� ���� ������ ��஢� �" << worst + 1 << ", �������� " << milk[worst] << " ���஢" << endl;

    return 0;
}