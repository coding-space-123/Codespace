#include <iostream>
#include <string>
using namespace std;

class Book {
    static int txt_count;
    static int ref_count;

    string name;
    string author;
    string type;
    string id;
    int digits;

public:
    void getData() {
        cout << "\nEnter book name: ";
        cin >> name;

        cout << "Enter author name: ";
        cin >> author;

        cout << "Enter book type (TXT / REF): ";
        cin >> type;

        cout << "Enter number of digits for ID: ";
        cin >> digits;

        generateID();
    }

    void generateID() {
        string numStr;

        if (type == "TXT") {
            txt_count++;
            id = "TXT";
            numStr = to_string(txt_count);
        }
        else if (type == "REF") {
            ref_count++;
            id = "REF";
            numStr = to_string(ref_count);
        }
        else {
            cout << "Invalid book type!" << endl;
            id = "INVALID";
            return;
        }

        // Add leading zeros
        int zeros = digits - numStr.length();
        while (zeros > 0) {
            id += "0";
            zeros--;
        }

        // Add number part
        id += numStr;
    }

    void showData() {
        cout << "\nBook Name : " << name;
        cout << "\nAuthor    : " << author;
        cout << "\nType      : " << type;
        cout << "\nBook ID   : " << id << endl;
    }

    static void count() {
        cout << "\nTotal Text Books     : " << txt_count;
        cout << "\nTotal Reference Books: " << ref_count << endl;
    }
};

// Static initialization
int Book::txt_count = 0;
int Book::ref_count = 0;

int main() {
    int n;

    cout << "Enter number of books: ";
    cin >> n;

    Book b[10];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Book " << i + 1 << " ---";
        b[i].getData();
    }

    for (int i = 0; i < n; i++) {
        b[i].showData();
    }

    Book::count();

    return 0;
}