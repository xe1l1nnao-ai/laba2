#include <iostream>
using namespace std;

int main() {
	int days, isStudent;
	cout << "Enter the number of overdue days: ";
	cin >> days;
	cout << "Enter student flag (0/1): ";
	cin >> isStudent;

	if (days < 0) {
		cout << "Overdue days cannot be negative" << endl;
		return 0;
	}

	double fine = 0;

	int d1 = days < 7 ? days : 7;
	fine += d1 * 0.5;

	if (days > 7) {
		int d2 = (days < 30 ? days : 30) - 7;
		fine += d2 * 1;
	}

	if (days > 30) {
		fine += (days - 30) * 2;
	}

	if (isStudent == 1) {
		fine *= 0.5;
	}

	cout << "Total fine: " << fine << endl;

	return 0;
}

