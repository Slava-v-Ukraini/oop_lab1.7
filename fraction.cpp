#include "fraction.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// ������������
Fraction::Fraction() : fractionalPart(0) {
    Init(DigitString(0), 0);
}

Fraction::Fraction(const DigitString& integer, unsigned short fractional) {
    Init(integer, fractional);
}

Fraction::Fraction(int integer, unsigned short fractional) {
    Init(DigitString(integer), fractional);
}

bool Fraction::GetIntegerPart(DigitString& value) const {
    value = integerPart;  
    return true;
}

bool Fraction::GetFractionalPart(unsigned short& value) const {
    value = fractionalPart;
    return true;
}

bool Fraction::SetIntegerPart(const DigitString& value) {
    integerPart = value;
    return true;
}

bool Fraction::SetFractionalPart(unsigned short value) {
    fractionalPart = value;
    return true;
}

// ��������� ������
bool Fraction::Init(const DigitString& integer, unsigned short fractional) {
    integerPart = integer;
    fractionalPart = fractional;
    return true;
}

bool Fraction::Read() {
    string intPart;
    cout << "������ ���� �������: ";
    cin >> intPart;

    DigitString ds;
    if (!ds.Init(intPart)) {
        return false;
    }

    unsigned short fracPart;
    cout << "������ ������� �������: ";
    cin >> fracPart;

    return Init(ds, fracPart);
}

void Fraction::Display() const {
    cout << toString();
}

string Fraction::toString() const {
    stringstream sout;
    sout << integerPart.toString() << "." << fractionalPart;
    return sout.str();
}

// ���������� ��������
Fraction Fraction::Add(const Fraction& other) const {
    //����������� � ������� ������
    double thisValue = ToDouble();
    double otherValue = other.ToDouble();
    double resultValue = thisValue + otherValue;

    // ��������� ���� �� ������� ������� ����������
    int resultInt = static_cast<int>(resultValue);
    double onlyFractionalPart = resultValue - resultInt;
    double scaledFraction = onlyFractionalPart * 10000; // ���������� �� ������
    double roundedFraction = round(scaledFraction); // ���������� �� ����������� ������
    unsigned short resultFrac = static_cast<unsigned short>(roundedFraction);
    return Fraction(resultInt, resultFrac);
}

Fraction Fraction::Subtract(const Fraction& other) const {
    double thisValue = ToDouble();
    double otherValue = other.ToDouble();
    double resultValue = thisValue - otherValue;
    
    // ���������� ���� �� ������� �������
    int resultInt = static_cast<int>(resultValue);
    double onlyFractionalPart = resultValue - resultInt;
    double scaledFraction = onlyFractionalPart * 10000;
    double roundedFraction = round(scaledFraction);
    unsigned short resultFrac = static_cast<unsigned short>(roundedFraction);
    return Fraction(resultInt, resultFrac);
}

Fraction Fraction::Multiply(const Fraction& other) const {
    double thisValue = ToDouble();
    double otherValue = other.ToDouble();
    double resultValue = thisValue * otherValue;

    // ���������� ���� �� ������� �������
    int resultInt = static_cast<int>(resultValue);
    double onlyFractionalPart = resultValue - resultInt;
    double scaledFraction = onlyFractionalPart * 10000;
    double roundedFraction = round(scaledFraction);
    unsigned short resultFrac = static_cast<unsigned short>(roundedFraction);
    return Fraction(resultInt, resultFrac);
}

// �������� ���������
bool Fraction::IsEqual(const Fraction& other) const {
    return fabs(ToDouble() - other.ToDouble()) < 1e-10;
}

bool Fraction::IsNotEqual(const Fraction& other) const {
    return !IsEqual(other);
}

bool Fraction::IsGreater(const Fraction& other) const {
    return ToDouble() > other.ToDouble();
}

bool Fraction::IsLess(const Fraction& other) const {
    return ToDouble() < other.ToDouble();
}

bool Fraction::IsGreaterOrEqual(const Fraction& other) const {
    return IsGreater(other) || IsEqual(other);
}

bool Fraction::IsLessOrEqual(const Fraction& other) const {
    return IsLess(other) || IsEqual(other);
}

// ������� ������
double Fraction::ToDouble() const {
    int intPart = integerPart.ToInt();
    double fracPart = static_cast<double>(fractionalPart) / 10000;

    // ������� ���� ���� �������
    if (intPart < 0) {
        return static_cast<double>(intPart) - fracPart;
    }
    else {
        return static_cast<double>(intPart) + fracPart;
    }
}