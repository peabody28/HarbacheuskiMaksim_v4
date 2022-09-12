// lab2.cpp : «Комплексное число».
#include <iostream>
#include <cmath>

class ComplexNumberSquare
{
private:
    double real;
    double imag;
 
public:
    ComplexNumberSquare(double _real, double _imag)
    {
        real = _real;
        imag = _imag;
    }

    friend std::ostream& operator << (std::ostream& out, ComplexNumberSquare c);
};

class ComplexNumber
{
private:
    double real;
    double imag;
public:
    ComplexNumber(double _real = 0, double _imag = 0)
    {
        real = _real;
        imag = _imag;
    }

    double ToDouble()
    {
        return sqrt(pow(real, 2) + pow(imag, 2));
    }

    ComplexNumberSquare Square()
    {
        return ComplexNumberSquare(pow(real, 2), pow(imag, 2));
    }

    friend void operator -- (ComplexNumber& num, int);
    friend ComplexNumber operator - (ComplexNumber c1, ComplexNumber c2);
    friend std::ostream& operator << (std::ostream& out, ComplexNumber c);
    
    ComplexNumber& operator = (ComplexNumber c1)
    {
        real = c1.real;
        imag = c1.imag;
        return *this;
    }

    void operator()(double _real, double _imag)
    {
        real = _real;
        imag = _imag;
    }

    void operator ++ (int) { real++; }

    ComplexNumber& operator + (ComplexNumber c2)
    {
        real += c2.real;
        imag += c2.imag;
        return *this;
    }

    bool operator == (ComplexNumber c2) 
    {
        return real == c2.real && imag == c2.imag;
    }
};

void operator -- (ComplexNumber& num, int) { num.real--; }

ComplexNumber operator - (ComplexNumber c1, ComplexNumber c2)
{
    return  ComplexNumber(c1.real - c2.real, c1.imag - c2.imag);
}

std::ostream& operator << (std::ostream& out, ComplexNumber c)
{
    return out << c.real << " " << c.imag << "i";
}
std::ostream& operator << (std::ostream& out, ComplexNumberSquare c)
{
    return out << c.real << " " << c.imag << "i";
}


int main()
{
    ComplexNumber a(2.5, 19.2);
    ComplexNumber b(16, 12);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    a--;
    std::cout << "(--) a = " << a << std::endl;
    a++;
    std::cout << "(++) a = " << a << std::endl;

    a = a + b;
    std::cout << "(+b) a = " << a << std::endl;
    a = a - b;
    std::cout << "(-b) a = " << a << std::endl << std::endl;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    a = b;
    std::cout << "(a = b) a = " << a << std::endl;

    a = ComplexNumber(6, -9);
    bool tr = b == b;
    std::cout << "b == b " << tr << std::endl;
    bool fl = a == b;
    std::cout << "a == b " << fl << std::endl << std::endl;

    ComplexNumber c;
    c(2.2, 12);
    std::cout << "c = " << c << std::endl;

    std::cout << "c to double = " << c.ToDouble() << std::endl;
    std::cout << "c to Square = " << c.Square() << std::endl;
     
    return 0;
}