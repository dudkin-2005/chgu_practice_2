#include <iostream>
using namespace std;

// �஢����, 㯮�冷祭 �� ���ᨢ �� �����⠭��
bool isAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

// �஢����, 㯮�冷祭 �� ���ᨢ �� �뢠���
bool isDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        if (arr[i] < arr[i + 1])
            return false;
    return true;
}

// ��।���� ⨯ 㯮�冷祭����
int checkOrder(int arr[], int size) {
    if (isAscending(arr, size)) return 1;
    if (isDescending(arr, size)) return -1;
    return 0;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = checkOrder(arr, size);

    cout << "���ᨢ: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    if (result == 1)
        cout << "���ᨢ 㯮�冷祭 �� �����⠭��." << endl;
    else if (result == -1)
        cout << "���ᨢ 㯮�冷祭 �� �뢠���." << endl;
    else
        cout << "���ᨢ �� 㯮�冷祭." << endl;

    return 0;
}