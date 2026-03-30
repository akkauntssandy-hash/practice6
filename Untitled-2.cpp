#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "", word;
    string minWord, maxWord;

    cout << "Введите слова:\n";

    
    while (cin >> word) {
        if (str == "") {
            minWord = maxWord = word;
        } else {
            if (word.length() < minWord.length())
                minWord = word;
            if (word.length() > maxWord.length())
                maxWord = word;
        }

        str += word + " ";
    }

    string result = "", temp = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            temp += str[i];
        } else {
            if (temp != "") {
                if (temp == minWord)
                    result += maxWord;
                else if (temp == maxWord)
                    result += minWord;
                else
                    result += temp;

                result += " ";
                temp = "";
            }
        }
    }

    cout << "Результат: " << result;

    return 0;
}
