#include <iostream>
// #include <conio.h>
#include <iomanip>
using namespace std;

class student {
    int rollno;
    int s1, s2, s3;
    char name[20];
    char class_name[10];

public:
    void getdata();
    void showdata();
    void print_line(char, int);
    int total_marks();
    float average();
    float percentage();
    void display_report(int);
};

void student::getdata() {
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Class: ";
    cin >> class_name;

    cout << "Enter Roll No: ";
    cin >> rollno;

    cout << "Enter marks of 3 subjects: \n";
    cout<<"maths:";
    cin >> s1 ;
    cout<<"science:";
    cin >> s2 ;
    cout<<"english:";
    cin >> s3 ;
}
void student::showdata() {
    cout<<"\nName:"<< name <<endl;
    cout << "Class: "<< class_name<<endl;

    cout << "Roll No: "<<rollno<<endl;
    cout <<"\nmarks of 3 subjects:\n ";
    cout<<"\nmaths:" <<s1<<endl;
    cout<<"\nscience:"<<s2 <<endl;
    cout<<"\nenglish:"<<s3 <<endl;
}

void student::print_line(char ch, int n) {
    for (int i = 0; i < n; i++)
        cout << ch;
    cout << endl;
}

int student::total_marks() {
    return s1 + s2 + s3;
}

float student::average() {
    return total_marks() / 3.0;
}

float student::percentage() {
    return (total_marks() / 300.0) * 100;
}

void student::display_report(int i) {

    print_line('=', 100);
    cout << setw(50) << "REPORT CARD" << endl;
    print_line('=', 100);

    cout << "Name of Student : " << name << endl;
    cout << "Class           : " << class_name << endl;
    cout << "Roll No         : " << rollno << endl;

    print_line('=', 100);
    cout << setw(8)  << "S.N";
    cout << setw(20) << "Subject";
    cout << setw(20) << "Max Marks";
    cout << setw(20) << "Obtained";
    cout << endl;

    print_line('=', 100);

    cout << setw(8) << i+1 << setw(20) << "Maths"
         << setw(20) << 100 << setw(20) << s1 << endl;

    cout << setw(8) << i+1 << setw(20) << "Physics"
         << setw(20) << 100 << setw(20) << s2 << endl;

    cout << setw(8) << i+1 << setw(20) << "Chemistry"
         << setw(20) << 100 << setw(20) << s3 << endl;

    print_line('-', 100);

    cout << "Total Marks   : " << total_marks() << endl;
    cout << "Average Marks : " << average() << endl;
    cout << "Percentage    : " << percentage() << "%" << endl << endl ;
    print_line('-', 100);
    cout << endl;
}

int main() {
    student s[3];

    for (int i = 0; i < 3; i++) {
        cout << "\nEnter details of student " << i + 1 << endl;
        s[i].getdata();   
    }
    for (int i = 0; i < 3; i++) {
        cout << "\nDetails of student " << i + 1 << endl;
        s[i].showdata();   
    }
    for (int i = 0; i < 3; i++){
        cout << setw(50) << "\n***Report Card of "<<i+1<<"Student***\n" << endl;
        s[i].print_line('-',100);
        // system("CLS");
        s[i].display_report(i);
        // getch();
    }

    return 0;
}
