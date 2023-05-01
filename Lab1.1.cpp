#include <iostream>


class ComplexNumber {
private: //модифікатор доступу
    double realPart;
    double imaginaryPart;

public: //модифікатор доступу
    ComplexNumber() : realPart(0.0), imaginaryPart(0.0) {
        std::cout << "Default constructor called" << std::endl;
    }

    ComplexNumber(double real, double imaginary) : realPart(real), imaginaryPart(imaginary) {
        std::cout << "Parameterized constructor called" << std::endl;
    }

    ~ComplexNumber() {
        std::cout << "Destructor called" << std::endl;
    }

    double getRealPart() {
        return realPart;
    }

    void setRealPart(double real) {
        realPart = real;
    }

    double getImaginaryPart() {
        return imaginaryPart;
    }

    void setImaginaryPart(double imaginary) {
        imaginaryPart = imaginary;
    }

    void print() {
        std::cout << "(" << realPart << " " << (imaginaryPart >= 0 ? "+" : "-") << " i" << fabs(imaginaryPart) << ")" << std::endl;
    }
};



int main() {
    ComplexNumber number1; // виклик конструктора без параметрів
    number1.print(); // вивід: (0.00 + i0.00)

    ComplexNumber number2(2.5, -3.2); // виклик конструктора з параметрами
    number2.print(); // вивід: (2.50 - i3.20)

    return 0;
}