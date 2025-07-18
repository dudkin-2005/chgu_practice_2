#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// �㭪�� ��室�� ᠬ�� ������� ᫮��
string longestWord(const string& text) {
    istringstream stream(text);
    string word, maxWord;

    while (stream >> word) {
        if (word.length() > maxWord.length())
            maxWord = word;
    }

    return maxWord;
}

// �㭪�� ��室�� ᠬ�� ���⪮� ᫮��
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
    cout << "������ ��ப� ��� ������� ᫮�: ";
    getline(cin, inputText);

    string longest = longestWord(inputText);
    string shortest = shortestWord(inputText);

    cout << "����� ������� ᫮��: " << longest << endl;
    cout << "����� ���⪮� ᫮��: " << shortest << endl;

    return 0;
}