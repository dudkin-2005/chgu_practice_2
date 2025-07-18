#include <iostream>
using namespace std;

// �㭪�� �஢����, 㯮�冷祭 �� ���ᨢ �� �����⠭��
bool isAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

// �㭪�� �뢮��� ��ப� ������ � १���� �஢�ન
void printRowAndResult(int row[], int size, int rowIndex) {
    cout << "��ப� " << rowIndex + 1 << ": ";
    for (int i = 0; i < size; ++i)
        cout << row[i] << " ";
    
    if (isAscending(row, size))
        cout << "-> 㯮�冷祭� �� �����⠭��";
    else
        cout << "-> �� 㯮�冷祭� �� �����⠭��";
    
    cout << endl;
}

int main() {
    int n, m;

    cout << "������ ࠧ��� ������ (n m): ";
    cin >> n >> m;

    // �������᪮� �뤥����� ����� ��� ������
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[m];

    // ���� ����⮢ ������
    cout << "������ ������ ������ �� ��ப��:\n";
    for (int i = 0; i < n; ++i) {
        cout << "��ப� " << i + 1 << ": ";
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
    }

    // �஢�ઠ � �뢮�
    cout << "\n������ ������:\n";
    for (int i = 0; i < n; ++i)
        printRowAndResult(matrix[i], m, i);

    // �᢮�������� �����
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}