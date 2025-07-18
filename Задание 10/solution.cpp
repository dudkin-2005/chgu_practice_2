#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>

using namespace std;

// Структура для хранения данных об абитуриенте
struct Abiturient {
    string name;
    int exam1;
    int exam2;
    int exam3;
};

// Функция загрузки данных из файла
vector<Abiturient> loadData(const string& filename) {
    vector<Abiturient> data;
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return data;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Abiturient a;
        ss >> a.name >> a.exam1 >> a.exam2 >> a.exam3;
        data.push_back(a);
    }

    inFile.close();
    return data;
}

// Функция фильтрации абитуриентов по условиям
vector<Abiturient> filterAbiturients(const vector<Abiturient>& input) {
    vector<Abiturient> result;

    for (const auto& a : input) {
        if (a.exam1 == 2) continue;  // Не допущен ко 2-му
        if (a.exam2 == 2) continue;  // Не допущен к 3-му
        result.push_back(a);
    }

    return result;
}

// Функция записи данных в файл
void saveData(const string& filename, const vector<Abiturient>& data) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return;
    }

    for (const auto& a : data) {
        outFile << a.name << " " << a.exam1 << " " << a.exam2 << " " << a.exam3 << endl;
    }

    outFile.close();
}

// Функция вывода данных на экран
void printData(const vector<Abiturient>& data, const string& title) {
    cout << title << endl;
    for (const auto& a : data) {
        cout << a.name << " " << a.exam1 << " " << a.exam2 << " " << a.exam3 << endl;
    }
    cout << "--------------------------" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); 
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    // Загрузка данных
    vector<Abiturient> all = loadData(inputFile);

    // Вывод входных данных
    printData(all, "Входные данные (все абитуриенты):");

    // Обработка
    vector<Abiturient> filtered = filterAbiturients(all);

    // Вывод выходных данных
    printData(filtered, "Допущенные абитуриенты:");

    // Сохранение в файл
    saveData(outputFile, filtered);

    cout << "Результат записан в файл: " << outputFile << endl;
    return 0;
}
