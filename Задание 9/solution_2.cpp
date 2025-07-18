#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Функция обработки строки: удаляет символы слева и справа от '#', но оставляет сам '#'
string removeAroundHash(const string& line) {
    string result;
    int len = line.length();

    for (int i = 0; i < len; ++i) {
        if (line[i] == '#') {
            // Удалить предыдущий символ из результата, если он существует
            if (!result.empty()) {
                result.pop_back();
            }
            result += '#';  // Оставляем сам '#'
            ++i; // Пропускаем символ справа от '#'
        } else {
            result += line[i];
        }
    }

    return result;
}

int main() {
    ifstream inFile("F1.txt");
    if (!inFile) {
        cerr << "Ошибка открытия F1.txt" << endl;
        return 1;
    }

    cout << "Содержимое файла F1.txt:" << endl;
    string line;
    vector<string> lines;

    while (getline(inFile, line)) {
        cout << line << endl;
        lines.push_back(line);
    }

    inFile.close();

    ofstream outFile("F2.txt");
    if (!outFile) {
        cerr << "Ошибка открытия F2.txt" << endl;
        return 1;
    }

    cout << "\nСодержимое файла F2.txt (после обработки):" << endl;
    for (const string& originalLine : lines) {
        string processedLine = removeAroundHash(originalLine);
        cout << processedLine << endl;
        outFile << processedLine << endl;
    }

    outFile.close();
    return 0;
}
