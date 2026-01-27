#include <iostream>
using namespace std;

class Date {
private:
    enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN,
                 JUL, AUG, SEP, OCT, NOV, DEC };

    int day, year;
    Month month;

    // Leap year check
    bool isLeapYear() const {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    }

    // Days in a month
    int daysInMonth() const {
        switch (month) {
            case FEB: return isLeapYear() ? 29 : 28;
            case APR: case JUN: case SEP: case NOV: return 30;
            default: return 31;
        }
    }

    // Adjust date forward
    void normalizeForward() {
        if (day > daysInMonth()) {
            day = 1;
            if (month == DEC) {
                month = JAN;
                year++;
            } else {
                month = Month(month + 1);
            }
        }
    }

    // Adjust date backward
    void normalizeBackward() {
        if (day < 1) {
            if (month == JAN) {
                month = DEC;
                year--;
            } else {
                month = Month(month - 1);
            }
            day = daysInMonth();
        }
    }

public:
    // Constructor
    Date() {
        day = 1;
        month = JAN;
        year = 2000;
    }

    // Input date
    void getData() {
        int m;
        cout << "Enter Day   : ";
        cin >> day;
        cout << "Enter Month : ";
        cin >> m;
        cout << "Enter Year  : ";
        cin >> year;
        month = Month(m);
    }

    // Default display
    void display() const {
        cout << "Date : " << day << "-" << month << "-" << year << endl;
    }

    // Numeric format (DD-MM-YYYY)
    void display(int) const {
        cout << "Date (DD-MM-YYYY): ";
        cout << (day < 10 ? "0" : "") << day << "-"
             << (month < 10 ? "0" : "") << month
             << "-" << year << endl;
    }

    // Month name function (NO string variable)
    const char* getMonthName() const {
        static const char* mon[] =
        {"","Jan","Feb","Mar","Apr","May","Jun",
              "Jul","Aug","Sep","Oct","Nov","Dec"};
        return mon[month];
    }

    // Month name format (DD-MON-YYYY)
    void display(char) const {
        cout << "Date (DD-MON-YYYY): ";
        cout << (day < 10 ? "0" : "") << day << "-"
             << getMonthName() << "-"
             << year << endl;
    }

    // Pre-increment (++d)
    Date operator++() {
        day++;
        normalizeForward();
        return *this;
    }

    // Post-increment (d++)
    Date operator++(int) {
        Date temp = *this;
        day++;
        normalizeForward();
        return temp;
    }

    // Pre-decrement (--d)
    Date operator--() {
        day--;
        normalizeBackward();
        return *this;
    }

    // Post-decrement (d--)
    Date operator--(int) {
        Date temp = *this;
        day--;
        normalizeBackward();
        return temp;
    }
};

int main() {
    Date d1, d2;
    int choice;

    cout << "\nEnter Date\n";
    d1.getData();
    d1.display();

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display numeric format\n";
        cout << "2. Display month name format\n";
        cout << "3. Pre increment (++date)\n";
        cout << "4. Post increment (date++)\n";
        cout << "5. Pre decrement (--date)\n";
        cout << "6. Post decrement (date--)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                d1.display(1);
                break;

            case 2:
                d1.display('m');
                break;

            case 3:
                d2 = ++d1;
                cout << "After ++date\n";
                d1.display('m');
                break;

            case 4:
                d2 = d1++;
                cout << "Old Date: ";
                d2.display('m');
                cout << "New Date: ";
                d1.display('m');
                break;

            case 5:
                d2 = --d1;
                d1.display('m');
                d2.display('m');
                break;

            case 6:
                d2 = d1--;
                cout << "Old Date: ";
                d2.display('m');
                cout << "New Date: ";
                d1.display('m');
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
