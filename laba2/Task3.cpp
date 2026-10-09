#include <iostream>

using namespace std;

int main() {
    char code;
    int days;
    double rate = 0.0;
    double fine = 0.0;

    cout << "Enter code (B, M, D): ";
    cin >> code;
    cout << "Enter days overdue: ";
    cin >> days;

    switch (code) {
    case 'B': case 'b': rate = 0.5; break;
    case 'M': case 'm': rate = 0.8; break;
    case 'D': case 'd': rate = 1.2; break;
    default:
        cout << "Error: unknown code\n";
        return 1;
    }

    switch (days < 0) {
    case 1:
        cout << "Error: negative days\n";
        return 1;
    }

    switch (days > 30) {
    case 1:
        fine = rate * days * 1.25;
        break;
    default:
        fine = rate * days;
    }

    cout << "Fine: " << fine << " rub.\n";

    return 0;
}
