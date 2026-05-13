#include<iostream>
#include<iomanip>
using namespace std;

class Time {
    int h, m, s;

public:
    Time() {
        h = 0; m = 0; s = 0;
    }

    Time(int hh, int mm, int ss) {
        h = hh; m = mm; s = ss;
    }

    void display() {
        cout << setw(2) << setfill('0') << h << ":"
             << setw(2) << setfill('0') << m << ":"
             << setw(2) << setfill('0') << s << endl;
    }

    // 🔹 Prefix ++
    Time operator++() {
        s++;
        if(s >= 60) {
            s = 0;
            m++;
        }
        if(m >= 60) {
            m = 0;
            h++;
        }
        if(h >= 24)
            h = 0;
        return *this;
    }

    // 🔹 Postfix ++
    Time operator++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    // 🔹 Prefix --
    Time operator--() {
        s--;
        if(s < 0) {
            s = 59;
            m--;
        }
        if(m < 0) {
            m = 59;
            h--;
        }
        if(h < 0)
            h = 23;
        return *this;
    }

    // 🔹 Input operator with validation loop
    friend istream& operator>>(istream& in, Time& t);

    // 🔹 Output operator
    friend ostream& operator<<(ostream& out, Time& t);
};

// ✅ Input with proper validation
istream& operator>>(istream& in, Time& t) {
    while(true) {
        cout<<"Enter hours (0-23): ";
        in>>t.h;
        cout<<"Enter minutes (0-59): ";
        in>>t.m;
        cout<<"Enter seconds (0-59): ";
        in>>t.s;

        if(t.h >= 0 && t.h < 24 &&
           t.m >= 0 && t.m < 60 &&
           t.s >= 0 && t.s < 60) {
            break;
        }
        else {
            cout<<"\n❌ Invalid time! Please enter again.\n\n";
        }
    }
    return in;
}

// Output
ostream& operator<<(ostream& out, Time& t) {
    out << setw(2) << setfill('0') << t.h << ":"
        << setw(2) << setfill('0') << t.m << ":"
        << setw(2) << setfill('0') << t.s;
    return out;
}

// 🔹 Main
int main() {
    Time t;

    cout<<"--- Time Input ---\n";
    cin>>t;

    cout<<"\nTime Entered: "<<t<<endl;

    cout<<"\nAfter Postfix Increment (t++): ";
    t++;
    cout<<t<<endl;

    cout<<"After Prefix Increment (++t): ";
    ++t;
    cout<<t<<endl;

    cout<<"After Prefix Decrement (--t): ";
    --t;
    cout<<t<<endl;

    return 0;
}
/*

*/