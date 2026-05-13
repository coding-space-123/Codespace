#include<iostream>
#include<iomanip>
using namespace std;

class Time {
    int h, m, s;

public:
    Time() {
        h = 0; m = 0; s = 0;
    }

    // Prefix ++
    Time operator++() {
        s++;
        if(s >= 60) { s = 0; m++; }
        if(m >= 60) { m = 0; h++; }
        if(h >= 24) h = 0;
        return *this;
    }

    // Postfix ++
    Time operator++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix --
    Time operator--() {
        s--;
        if(s < 0) { s = 59; m--; }
        if(m < 0) { m = 59; h--; }
        if(h < 0) h = 23;
        return *this;
    }

    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, Time& t);
};


// 🔹 Custom manipulators (CORRECT WAY)
ostream& hour(ostream& os) {
    os << " hr ";
    return os;
}

ostream& minm(ostream& os) {
    os << " min ";
    return os;
}

ostream& sec(ostream& os) {
    os << " sec ";
    return os;
}


// Input
istream& operator>>(istream& in, Time& t) {
    while(true) {
        cout<<"Enter hours (0-23): ";
        in>>t.h;
        cout<<"Enter minutes (0-59): ";
        in>>t.m;
        cout<<"Enter seconds (0-59): ";
        in>>t.s;

        if(t.h>=0 && t.h<24 && t.m>=0 && t.m<60 && t.s>=0 && t.s<60)
            break;
        else
            cout<<"\nInvalid! Try again\n\n";
    }
    return in;
}


// Output
ostream& operator<<(ostream& out, Time& t) {
    out << setw(2) << setfill('0') << t.h << hour
        << setw(2) << setfill('0') << t.m << minm
        << setw(2) << setfill('0') << t.s << sec;
    return out;
}


int main() {
    Time t;

    cin >> t;

    cout << "\nTime: " << t << endl;

    t++;
    cout << "After t++: " << t << endl;

    ++t;
    cout << "After ++t: " << t << endl;

    --t;
    cout << "After --t: " << t << endl;

    return 0;
}
/*
Enter hours (0-23): 5 
Enter minutes (0-59): 7
Enter seconds (0-59): 234

Invalid! Try again

Enter hours (0-23): 23
Enter minutes (0-59): 45
Enter seconds (0-59): 2

Time: 23 hr 45 min 02 sec 
After t++: 23 hr 45 min 03 sec 
After ++t: 23 hr 45 min 04 sec 
After --t: 23 hr 45 min 03 sec 
*/