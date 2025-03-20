#pragma once
#include "digitString.h"

using namespace std;

class Fraction {
private:
    DigitString integerPart;  // Ціла частина
    unsigned short fractionalPart;  // Дробова частина - беззнакове коротке ціле

public:
    // Конструктори
    Fraction();
    Fraction(const DigitString& integer, unsigned short fractional);
    Fraction(int integer, unsigned short fractional);

    bool GetIntegerPart(DigitString& value) const;
    bool GetFractionalPart(unsigned short& value) const;
    bool SetIntegerPart(const DigitString& value);
    bool SetFractionalPart(unsigned short value);

    bool Init(const DigitString& integer, unsigned short fractional);
    bool Read();
    void Display() const;
    string toString() const;

    Fraction Add(const Fraction& other) const;
    Fraction Subtract(const Fraction& other) const;
    Fraction Multiply(const Fraction& other) const;

    bool IsEqual(const Fraction& other) const;
    bool IsNotEqual(const Fraction& other) const;
    bool IsGreater(const Fraction& other) const;
    bool IsLess(const Fraction& other) const;
    bool IsGreaterOrEqual(const Fraction& other) const;
    bool IsLessOrEqual(const Fraction& other) const;

    // Допоміжні методи
    double ToDouble() const;
};