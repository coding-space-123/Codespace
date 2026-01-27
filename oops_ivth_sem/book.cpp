#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Book {
    static int txt_count;
    static int ref_count;

    char name[50];
    char author[50];
    char type[10];
    char id[20];
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
        char numStr[10];

        if (strcmp(type, "TXT") == 0) {
            txt_count++;
            strcpy(id, "TXT");
            sprintf(numStr, "%d", txt_count);
        }
        else if(strcmp(type, "REF") == 0) {
            ref_count++;
            strcpy(id, "REF");
            sprintf(numStr, "%d", ref_count);
        }
        else {
            cout << "Invalid book type!" << endl;
            strcpy(id, "INVALID");
            return;
        }

        // add leading zeros
        while (strlen(numStr) < digits) {
            strcat(id, "0");
            digits--;
        }

        // add number part
        strcat(id, numStr);
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
