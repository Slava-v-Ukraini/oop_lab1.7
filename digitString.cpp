#include "digitString.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// ������������
DigitString::DigitString() {
    Init("0");
}

DigitString::DigitString(const string& value) {
    Init(value);
}

DigitString::DigitString(int value) {
    stringstream sout;
    sout << value;
    Init(sout.str());
}

bool DigitString::GetDigits(string& value) const {
    value = digits;
    return true;
}

bool DigitString::SetDigits(const string& value) {
    return Init(value);
}

bool DigitString::Init(const string& value) {
    // ��������, �� ����� ������ ����� ����� (������� ������ ������ - ���� ����)
    if (value.empty()) {
        digits = "0";
        return false;
    }

    size_t startPos = 0;
    bool isNegative = false;

    // �������� �� ��'���� �����
    if (value[0] == '-') {
        isNegative = true;
        startPos = 1;
    }
    else if (value[0] == '+') {
        startPos = 1;
    }

    // ��������, �� ����� ����� ���������� � ����
    for (size_t i = startPos; i < value.length(); i++) {
        if (!isdigit(value[i])) {
            digits = "0";
            return false;
        }
    }

    // ��������� ������� ����
    size_t firstNonZero = value.find_first_not_of('0', startPos);
    if (firstNonZero == string::npos) {
        digits = "0";
    }
    else {
        if (isNegative) {
            digits = "-" + value.substr(firstNonZero);
        }
        else {
            digits = value.substr(firstNonZero);
        }
    }

    // �������� �� ����
    if (digits == "" || digits == "-0" || digits == "-") {
        digits = "0";
    }

    return true;
}

bool DigitString::Read() {
    cout << "������ ���� �����: ";
    string input;
    cin >> input;
    return Init(input);
}

void DigitString::Display() const {
    cout << toString();
}

string DigitString::toString() const {
    return digits;
}

// ���������� ��������
DigitString DigitString::Add(const DigitString& other) const {
    int result = ToInt() + other.ToInt();
    return DigitString(result);
}

DigitString DigitString::Subtract(const DigitString& other) const {
    int result = ToInt() - other.ToInt();
    return DigitString(result);
}

DigitString DigitString::Multiply(const DigitString& other) const {
    int result = ToInt() * other.ToInt();
    return DigitString(result);
}

DigitString DigitString::Divide(const DigitString& other) const {
    if (other.ToInt() == 0) {
        cerr << "�������: ������ �� ����" << endl;
        return DigitString(0);
    }
    int result = ToInt() / other.ToInt();
    return DigitString(result);
}

DigitString DigitString::Modulo(const DigitString& other) const {
    if (other.ToInt() == 0) {
        cerr << "�������: ������ �� ����" << endl;
        return DigitString(0);
    }
    int result = ToInt() % other.ToInt();
    return DigitString(result);
}

// �������� ���������
bool DigitString::IsEqual(const DigitString& other) const {
    return ToInt() == other.ToInt();
}

bool DigitString::IsNotEqual(const DigitString& other) const {
    return ToInt() != other.ToInt();
}

bool DigitString::IsGreater(const DigitString& other) const {
    return ToInt() > other.ToInt();
}

bool DigitString::IsLess(const DigitString& other) const {
    return ToInt() < other.ToInt();
}

bool DigitString::IsGreaterOrEqual(const DigitString& other) const {
    return ToInt() >= other.ToInt();
}

bool DigitString::IsLessOrEqual(const DigitString& other) const {
    return ToInt() <= other.ToInt();
}

// ������� ������
int DigitString::ToInt() const {
    stringstream sout(digits);
    int value;
    sout >> value;
    return value;
}

bool DigitString::IsNegative() const {
    return !digits.empty() && digits[0] == '-';
}