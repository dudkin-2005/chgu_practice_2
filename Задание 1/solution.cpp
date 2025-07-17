#include <iostream>
#include <cmath>
#include <iomanip>  // ��� std::setprecision

int main() {
    double x1, y1; // ���न���� ����� ���孥� ���設�
    double x2, y2; // ���न���� �ࠢ�� ������ ���設�

    // ���� ���न���
    std::cout << "������ ���न���� ����� ���孥� ���設� (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "������ ���न���� �ࠢ�� ������ ���設� (x2 y2): ";
    std::cin >> x2 >> y2;

    // ���᫥��� ����� ��஭� ������
    double side = std::abs(x2 - x1); // ����� ⠪�� ����� std::abs(y2 - y1)

    // ���᫥��� ����� ���������
    double diagonal = side * std::sqrt(2);

    // ���न���� 業�� ������ (�窠 ����祭�� ����������)
    double center_x = (x1 + x2) / 2.0;
    double center_y = (y1 + y2) / 2.0;

    // �뢮� १���⮢
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "����� ��஭� ������: " << side << std::endl;
    std::cout << "����� ��������� ������: " << diagonal << std::endl;
    std::cout << "���न���� �窨 ����祭�� ����������: (" 
              << center_x << ", " << center_y << ")" << std::endl;

    return 0;
}