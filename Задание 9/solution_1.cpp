#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Функция находит самое длинное слово
string longestWord(const string& text) {
    istringstream stream(text);
    string word, maxWord;

    while (stream >> word) {
        if (word.length() > maxWord.length())
            maxWord = word;
    }

    return maxWord;
}

// Функция находит самое короткое слово
string shortestWord(const string& text) {
    istringstream stream(text);
    string word, minWord;

    while (stream >> word) {
        if (minWord.empty() || word.length() < minWord.length())
            minWord = word;
    }

    return minWord;
}

int main() {
    string inputText;
    cout << "Введите строку для анализа слов: ";
    getline(cin, inputText);

    string longest = longestWord(inputText);
    string shortest = shortestWord(inputText);

    cout << "Самое длинное слово: " << longest << endl;
    cout << "Самое короткое слово: " << shortest << endl;

    return 0;
}