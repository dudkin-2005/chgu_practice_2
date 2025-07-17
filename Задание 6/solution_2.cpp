#include <iostream>
#include <cmath>
using namespace std;

// ���� ���ᨢ�
void inputArray(double arr[], int size) {
    cout << "������ ���न���� �祪 �� ��אַ�:\n";
    for (int i = 0; i < size; ++i) {
        cout << "��窠 " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// �뢮� ���ᨢ�
void outputArray(double arr[], int size) {
    cout << "���ᨢ �祪:\n";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// ����� �殮��
double centerOfMass(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return sum / size;
}

// ���� �������� 㤠���� ���
int farthestFromCenter(double arr[], int size, double center) {
    int index = 0;
    double maxDist = abs(arr[0] - center);
    for (int i = 1; i < size; ++i) {
        double dist = abs(arr[i] - center);
        if (dist > maxDist) {
            maxDist = dist;
            index = i;
        }
    }
    return index;
}

// ������� ����� �� �������
void removeElement(double arr[], int& size, int index) {
    for (int i = index; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    --size;
}

int main() {
    int size = 5;
    double points[size];

    inputArray(points, size);
    outputArray(points, size);

    double center = centerOfMass(points, size);
    cout << "����� �殮��: " << center << endl;

    int farIndex = farthestFromCenter(points, size, center);
    cout << "�������� 㤠�񭭠� �窠: " << points[farIndex] << " (������ " << farIndex << ")" << endl;

    removeElement(points, size, farIndex);
    cout << "���ᨢ ��᫥ 㤠����� �窨:\n";
    outputArray(points, size);

    return 0;
}