#include <iostream>
#include "DigitString.h"
#include "Fraction.h"

using namespace std;

int main() {
    // ������������ ����� ��� �������� ��������
    setlocale(LC_ALL, "Ukrainian");

    cout << "=== �������� ��� ������ � ������� DigitString �� Fraction ===" << endl;

    // ������� 1: ������ � ������ DigitString
    cout << "\n-- ������������ ��� ������� ����� DigitString --" << endl;

    // ��� �����
    DigitString ds1, ds2;
    cout << "������ ����� �����: ";
    ds1.Read();

    cout << "������ ����� �����: ";
    ds2.Read();

    cout << "\n������������ ��� �������� ��� ����� " << ds1.toString() << " � " << ds2.toString() << ":" << endl;

    // ������������ ��� ��������
    // 1. ���������
    DigitString addResult = ds1.Add(ds2);
    cout << "���������: " << ds1.toString() << " + " << ds2.toString()
        << " = " << addResult.toString() << endl;

    // 2. ³�������
    DigitString subResult = ds1.Subtract(ds2);
    cout << "³�������: " << ds1.toString() << " - " << ds2.toString()
        << " = " << subResult.toString() << endl;

    // 3. ��������
    DigitString mulResult = ds1.Multiply(ds2);
    cout << "��������: " << ds1.toString() << " * " << ds2.toString()
        << " = " << mulResult.toString() << endl;

    // 4. ĳ�����
    if (ds2.ToInt() != 0) {
        DigitString divResult = ds1.Divide(ds2);
        cout << "ĳ�����: " << ds1.toString() << " / " << ds2.toString()
            << " = " << divResult.toString() << endl;
    }
    else {
        cout << "ĳ�����: ��������� �������� (������ �� ����)" << endl;
    }

    // 5. ������� �� ������
    if (ds2.ToInt() != 0) {
        DigitString modResult = ds1.Modulo(ds2);
        cout << "������� �� ������: " << ds1.toString() << " % " << ds2.toString()
            << " = " << modResult.toString() << endl;
    }
    else {
        cout << "������� �� ������: ��������� �������� (������ �� ����)" << endl;
    }

    // 6. ���������
    cout << "\n���������� ���������:" << endl;
    cout << ds1.toString() << " == " << ds2.toString() << " : "
        << (ds1.IsEqual(ds2) ? "���" : "ͳ") << endl;
    cout << ds1.toString() << " != " << ds2.toString() << " : "
        << (ds1.IsNotEqual(ds2) ? "���" : "ͳ") << endl;
    cout << ds1.toString() << " > " << ds2.toString() << " : "
        << (ds1.IsGreater(ds2) ? "���" : "ͳ") << endl;
    cout << ds1.toString() << " < " << ds2.toString() << " : "
        << (ds1.IsLess(ds2) ? "���" : "ͳ") << endl;
    cout << ds1.toString() << " >= " << ds2.toString() << " : "
        << (ds1.IsGreaterOrEqual(ds2) ? "���" : "ͳ") << endl;
    cout << ds1.toString() << " <= " << ds2.toString() << " : "
        << (ds1.IsLessOrEqual(ds2) ? "���" : "ͳ") << endl;

    // ������� 2: ������ � ������ Fraction
    cout << "\n-- ������������ ��� ������� ����� Fraction --" << endl;

    // ��� �����
    Fraction f1, f2;
    cout << "������ ������ ���: ";
    f1.Read();

    cout << "������ ������ ���: ";
    f2.Read();

    cout << "\n������������ ��� �������� ��� ����� " << f1.toString() << " � " << f2.toString() << ":" << endl;

    // ������������ ��� ��������
    // 1. ���������
    Fraction fAddResult = f1.Add(f2);
    cout << "���������: " << f1.toString() << " + " << f2.toString()
        << " = " << fAddResult.toString() << endl;

    // 2. ³�������
    Fraction fSubResult = f1.Subtract(f2);
    cout << "³�������: " << f1.toString() << " - " << f2.toString()
        << " = " << fSubResult.toString() << endl;

    // 3. ��������
    Fraction fMulResult = f1.Multiply(f2);
    cout << "��������: " << f1.toString() << " * " << f2.toString()
        << " = " << fMulResult.toString() << endl;

    // 4. ���������
    cout << "\n���������� ���������:" << endl;
    cout << f1.toString() << " == " << f2.toString() << " : "
        << (f1.IsEqual(f2) ? "���" : "ͳ") << endl;
    cout << f1.toString() << " != " << f2.toString() << " : "
        << (f1.IsNotEqual(f2) ? "���" : "ͳ") << endl;
    cout << f1.toString() << " > " << f2.toString() << " : "
        << (f1.IsGreater(f2) ? "���" : "ͳ") << endl;
    cout << f1.toString() << " < " << f2.toString() << " : "
        << (f1.IsLess(f2) ? "���" : "ͳ") << endl;
    cout << f1.toString() << " >= " << f2.toString() << " : "
        << (f1.IsGreaterOrEqual(f2) ? "���" : "ͳ") << endl;
    cout << f1.toString() << " <= " << f2.toString() << " : "
        << (f1.IsLessOrEqual(f2) ? "���" : "ͳ") << endl;

    cout << "\n������ �� ������������ ��������!" << endl;

    return 0;
}