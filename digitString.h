#pragma once
#include <string>

using namespace std;

class DigitString {
private:
    string digits;

public:
    // Конструктори
    DigitString();
    DigitString(const string& value);
    DigitString(int value);

    bool GetDigits(string& value) const;
    bool SetDigits(const string& value);

    bool Init(const string& value);
    bool Read();
    void Display() const;
    string toString() const;

    DigitString Add(const DigitString& other) const;
    DigitString Subtract(const DigitString& other) const;
    DigitString Multiply(const DigitString& other) const;
    DigitString Divide(const DigitString& other) const;
    DigitString Modulo(const DigitString& other) const;

    bool IsEqual(const DigitString& other) const;
    bool IsNotEqual(const DigitString& other) const;
    bool IsGreater(const DigitString& other) const;
    bool IsLess(const DigitString& other) const;
    bool IsGreaterOrEqual(const DigitString& other) const;
    bool IsLessOrEqual(const DigitString& other) const;

    // Допоміжні методи
    int ToInt() const;
    bool IsNegative() const;
};