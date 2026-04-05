#include <iostream>
using namespace std;

class Manip {
    int num, base;

public:
    Manip(int n, int b)
    {
        num = n ;
        base = b;
    } 
    friend ostream& manipulator(ostream& out, Manip m);
    
};
ostream& manipulator(ostream& out, Manip m) {
    int n = m.num;
    char res[50];
    int i = 0;
    cout << "\nbase: " << m.base << endl;
    if(n == 0) {
        out << 0;
        return out;
    }

    while(n > 0) {
        int rem = n % m.base;
        res[i++] = (rem < 10) ? rem + '0' : rem - 10 + 'A';
        n /= m.base;
    }

    for(int j = i-1; j >= 0; j--)
        out << res[j];

    return out;
}
int main() {
    int num, choice;
    int base;

    cout << "\nChoose conversion:\n";
    cout << "1. Binary\n";
    cout << "2. Octal\n";
    cout << "3. Decimal\n";
    cout << "4. Hexadecimal\n";
    cout << "5. Exit\n";
    cout << "Enter number: ";
    cin >> num;
    do {
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: base = 2; break;
            case 2: base = 8; break;
            case 3: base = 10; break;
            case 4: base = 16; break;
            case 5: exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
        }
        Manip m(num, base);
        cout << "Result: ";
        manipulator(cout, m) << endl;
    } while(1);

    
    

    return 0;
}