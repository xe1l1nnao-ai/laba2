#include <iostream>
using namespace std;

int main() {
	int days, lost, isStudent;
	cout << "Enter the number of overdue days: ";
	cin >> days;
	cout << "Enter lost book flag (0/1): ";
	cin >> lost;
	cout << "Enter student flag (0/1): ";
	cin >> isStudent;

	if (days < 0) {
		cout << "Overdue days cannot be negative" << endl;
		return 0;
	}

	double fine = 0;

	if (lost == 1) {
		fine = 30;
		cout << "Reason: lost book" << endl;
	}
	else {
		if (days <= 10) {
			fine = days * 0.5;
		}
		else {
			fine = 10 * 0.5 + (days - 10) * 1;
		}

		if (isStudent == 1) {
			fine *= 0.5;
			cout << "Reason: overdue, student discount" << endl;
		}
		else {
			cout << "Reason: overdue" << endl;
		}
	}

	cout << "Total fine: " << fine << endl;

	return 0;
}