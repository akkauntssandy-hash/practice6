#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;

    int segments[10] = {0};

    int score;

    int excellent = 0;
    int good = 0;
    int satisfactory = 0;
    int unsatisfactory = 0;

    for (int i = 0; i < n; i++) {
        cout << "Введите рейтинг студента (0-100): ";
        cin >> score;

        if (score < 0 || score > 100) {
            cout << "Ошибка! Введите число от 0 до 100\n";
            i--;
        }
        else {
            int index = score / 10;
            if (score == 100)
                index = 9;

            segments[index]++;

            if (score >= 85)
                excellent++;
            else if (score >= 75)
                good++;
            else if (score >= 60)
                satisfactory++;
            else
                unsatisfactory++;
        }
    }

    cout << "\nПроцент студентов по сегментам:\n";

    for (int i = 0; i < 10; i++) {
        double percent = segments[i] * 100.0 / n;

        if (i != 9)
            cout << i * 10 << "-" << i * 10 + 9
                 << " : " << percent << "%\n";
        else
            cout << "90-100 : " << percent << "%\n";
    }

    cout << "\nПредварительные оценки:\n";

    cout << "Отлично: "
         << excellent * 100.0 / n << "%\n";

    cout << "Хорошо: "
         << good * 100.0 / n << "%\n";

    cout << "Удовлетворительно: "
         << satisfactory * 100.0 / n << "%\n";

    cout << "Неудовлетворительно: "
         << unsatisfactory * 100.0 / n << "%\n";

    return 0;
}