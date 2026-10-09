#include <iostream>

using namespace std;

int main() {
    char code;
    int days;
    char lost;
    char student;
    double rate = 0.0;
    double fixed = 0.0;
    double fine = 0.0;

    cout << "Enter code (B, M, D): ";
    cin >> code;
    cout << "Enter days overdue: ";
    cin >> days;
    cout << "Is it lost? (y/n): ";
    cin >> lost;
    cout << "Is it a student? (y/n): ";
    cin >> student;

    // Ставка и фиксированная стоимость по коду
    switch (code) {
    case 'B': case 'b': rate = 0.5; fixed = 25; break;
    case 'M': case 'm': rate = 0.8; fixed = 35; break;
    case 'D': case 'd': rate = 1.2; fixed = 50; break;
    default:
        cout << "Error: unknown code\n";
        return 1;
    }

    // Проверка отрицательной просрочки
    switch (days < 0) {
    case 1:
        cout << "Error: negative days\n";
        return 1;
    }

    // Основной сценарий
    switch (lost == 'y' || lost == 'Y') {
    case 1:
        // Материал потерян — фиксированный штраф без скидок
        fine = fixed;
        cout << "Scenario: lost, fixed fine\n";
        break;
    default:
        // Не потерян — обычный штраф
        fine = rate * days;

        // Скидка студенту 50%
        switch (student == 'y' || student == 'Y') {
        case 1:
            fine *= 0.5;
            break;
        }

        // Просрочка > 20 дней — добавить сбор 5
        switch (days > 20) {
        case 1:
            fine += 5;
            break;
        }

        cout << "Scenario: normal";
        switch (student == 'y' || student == 'Y') {
        case 1: cout << ", student discount"; break;
        }
        switch (days > 20) {
        case 1: cout << ", extra fee"; break;
        }
        cout << "\n";
    }

    cout << "Fine: " << fine << " rub.\n";

    return 0;
}
