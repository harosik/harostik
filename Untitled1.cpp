#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8); // Для вывода в консоль (UTF-8)
    SetConsoleCP(CP_UTF8); // Для ввода с клавиатуры (UTF-8)
    int A;
    cout << "Введите число от 1 до 1000 (я попробую угадать его): ";
    cin >> A;
    // Проверка на корректность введенного числа
    if (A < 1 || A > 1000) {
        cout << "Число вне диапазона. Пожалуйста, введите число от 1 до 1000." << endl;
        return 1;
    }
    // Генерация случайных чисел и дача подсказок
    int low = 1;
    int high = 1000;
    int guess;
    int attempts = 0;
    cout << "Я попробую угадать ваше число! Отвечайте 'б', если мое число слишком большое, 'м', если оно слишком маленькое, и 'т', если я угадал." << endl;
    while (true) {
        guess = (low + high) / 2;  // Среднее значение между low и high
        attempts++;
        cout << "Это число " << guess << "? (б/м/т): ";
        char response;
        cin >> response;
        if (response == 'б') {
            high = guess - 1;  // Если мое число слишком большое, уменьшаем диапазон
        }
        else if (response == 'м') {
            low = guess + 1;  // Если мое число слишком маленькое, увеличиваем диапазон
        }
        else if (response == 'т') {
            cout << "Ура! Я угадал ваше число за " << attempts << " попыток!" << endl;
            break;  // Если число угадано, выходим из цикла
        }
        else {
            cout << "Неверный ввод. Пожалуйста, введите 'б' для слишком большого, 'м' для слишком малого или 'т' для правильного." << endl;
        }
    }
    return 0;
}