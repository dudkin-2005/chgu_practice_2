#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// �㭪�� ��ࠡ�⪨ ��ப�: 㤠��� ᨬ���� ᫥�� � �ࠢ� �� '#', �� ��⠢��� ᠬ '#'
string removeAroundHash(const string& line) {
    string result;
    int len = line.length();

    for (int i = 0; i < len; ++i) {
        if (line[i] == '#') {
            // ������� �।��騩 ᨬ��� �� १����, �᫨ �� �������
            if (!result.empty()) {
                result.pop_back();
            }
            result += '#';  // ��⠢�塞 ᠬ '#'
            ++i; // �ய�᪠�� ᨬ��� �ࠢ� �� '#'
        } else {
            result += line[i];
        }
    }

    return result;
}

int main() {
    ifstream inFile("F1.txt");
    if (!inFile) {
        cerr << "�訡�� ������ F1.txt" << endl;
        return 1;
    }

    cout << "����ন��� 䠩�� F1.txt:" << endl;
    string line;
    vector<string> lines;

    while (getline(inFile, line)) {
        cout << line << endl;
        lines.push_back(line);
    }

    inFile.close();

    ofstream outFile("F2.txt");
    if (!outFile) {
        cerr << "�訡�� ������ F2.txt" << endl;
        return 1;
    }

    cout << "\n����ন��� 䠩�� F2.txt (��᫥ ��ࠡ�⪨):" << endl;
    for (const string& originalLine : lines) {
        string processedLine = removeAroundHash(originalLine);
        cout << processedLine << endl;
        outFile << processedLine << endl;
    }

    outFile.close();
    return 0;
}
