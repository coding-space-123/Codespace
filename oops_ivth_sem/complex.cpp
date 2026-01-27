#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    // Default constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }

    // Function to input data from user
    void getData() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> img;
    }

    // Function to set data manually
    void setData(int r, int i) {
        real = r;
        img = i;
    }

    // Function to display complex number
    void display() {
        if (img >= 0)
            cout << real << " + " << img << "i" << endl;
        else
            cout << real << " - " << -img << "i" << endl;
    }

    // Operator overloading for addition
    Complex operator + (Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    // Operator overloading for subtraction
    Complex operator - (Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.img = img - c.img;
        return temp;
    }

    // Operator overloading for multiplication
    Complex operator * (Complex c) {
        Complex temp;
        temp.real = real * c.real - img * c.img;
        temp.img = real * c.img + img * c.real;
        return temp;
    }

    // Operator overloading for division
    Complex operator / (Complex c) {
        Complex temp;
        int denominator = c.real * c.real + c.img * c.img;
        if (denominator == 0) {
            cout << "Division by zero error!" << endl;
            temp.real = 0;
            temp.img = 0;
            return temp;
        }
        temp.real = (real * c.real + img * c.img) / denominator;
        temp.img = (img * c.real - real * c.img) / denominator;
        return temp;
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    c1.getData();

    cout << "Enter second complex number:\n";
    c2.getData();

    Complex sum = c1 + c2;
    cout << "\nAddition: ";
    sum.display();

    Complex diff = c1 - c2;
    cout << "Subtraction: ";
    diff.display();

    Complex prod = c1 * c2;
    cout << "Multiplication: ";
    prod.display();

    Complex div = c1 / c2;
    cout << "Division: ";
    div.display();

    return 0;
}