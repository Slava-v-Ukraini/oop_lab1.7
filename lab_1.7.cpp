#include <iostream>
#include "DigitString.h"
#include "Fraction.h"

using namespace std;

int main() {
    // Налаштування локалі для підтримки кирилиці
    setlocale(LC_ALL, "Ukrainian");

    cout << "=== Програма для роботи з класами DigitString та Fraction ===" << endl;

    // Частина 1: Робота з класом DigitString
    cout << "\n-- Демонстрація всіх функцій класу DigitString --" << endl;

    // Ввід чисел
    DigitString ds1, ds2;
    cout << "Введіть перше число: ";
    ds1.Read();

    cout << "Введіть друге число: ";
    ds2.Read();

    cout << "\nДемонстрація всіх операцій для чисел " << ds1.toString() << " і " << ds2.toString() << ":" << endl;

    // Демонстрація всіх операцій
    // 1. Додавання
    DigitString addResult = ds1.Add(ds2);
    cout << "Додавання: " << ds1.toString() << " + " << ds2.toString()
        << " = " << addResult.toString() << endl;

    // 2. Віднімання
    DigitString subResult = ds1.Subtract(ds2);
    cout << "Віднімання: " << ds1.toString() << " - " << ds2.toString()
        << " = " << subResult.toString() << endl;

    // 3. Множення
    DigitString mulResult = ds1.Multiply(ds2);
    cout << "Множення: " << ds1.toString() << " * " << ds2.toString()
        << " = " << mulResult.toString() << endl;

    // 4. Ділення
    if (ds2.ToInt() != 0) {
        DigitString divResult = ds1.Divide(ds2);
        cout << "Ділення: " << ds1.toString() << " / " << ds2.toString()
            << " = " << divResult.toString() << endl;
    }
    else {
        cout << "Ділення: Неможливо виконати (ділення на нуль)" << endl;
    }

    // 5. Залишок від ділення
    if (ds2.ToInt() != 0) {
        DigitString modResult = ds1.Modulo(ds2);
        cout << "Залишок від ділення: " << ds1.toString() << " % " << ds2.toString()
            << " = " << modResult.toString() << endl;
    }
    else {
        cout << "Залишок від ділення: Неможливо виконати (ділення на нуль)" << endl;
    }

    // 6. Порівняння
    cout << "\nРезультати порівняння:" << endl;
    cout << ds1.toString() << " == " << ds2.toString() << " : "
        << (ds1.IsEqual(ds2) ? "Так" : "Ні") << endl;
    cout << ds1.toString() << " != " << ds2.toString() << " : "
        << (ds1.IsNotEqual(ds2) ? "Так" : "Ні") << endl;
    cout << ds1.toString() << " > " << ds2.toString() << " : "
        << (ds1.IsGreater(ds2) ? "Так" : "Ні") << endl;
    cout << ds1.toString() << " < " << ds2.toString() << " : "
        << (ds1.IsLess(ds2) ? "Так" : "Ні") << endl;
    cout << ds1.toString() << " >= " << ds2.toString() << " : "
        << (ds1.IsGreaterOrEqual(ds2) ? "Так" : "Ні") << endl;
    cout << ds1.toString() << " <= " << ds2.toString() << " : "
        << (ds1.IsLessOrEqual(ds2) ? "Так" : "Ні") << endl;

    // Частина 2: Робота з класом Fraction
    cout << "\n-- Демонстрація всіх функцій класу Fraction --" << endl;

    // Ввід дробів
    Fraction f1, f2;
    cout << "Введіть перший дріб: ";
    f1.Read();

    cout << "Введіть другий дріб: ";
    f2.Read();

    cout << "\nДемонстрація всіх операцій для дробів " << f1.toString() << " і " << f2.toString() << ":" << endl;

    // Демонстрація всіх операцій
    // 1. Додавання
    Fraction fAddResult = f1.Add(f2);
    cout << "Додавання: " << f1.toString() << " + " << f2.toString()
        << " = " << fAddResult.toString() << endl;

    // 2. Віднімання
    Fraction fSubResult = f1.Subtract(f2);
    cout << "Віднімання: " << f1.toString() << " - " << f2.toString()
        << " = " << fSubResult.toString() << endl;

    // 3. Множення
    Fraction fMulResult = f1.Multiply(f2);
    cout << "Множення: " << f1.toString() << " * " << f2.toString()
        << " = " << fMulResult.toString() << endl;

    // 4. Порівняння
    cout << "\nРезультати порівняння:" << endl;
    cout << f1.toString() << " == " << f2.toString() << " : "
        << (f1.IsEqual(f2) ? "Так" : "Ні") << endl;
    cout << f1.toString() << " != " << f2.toString() << " : "
        << (f1.IsNotEqual(f2) ? "Так" : "Ні") << endl;
    cout << f1.toString() << " > " << f2.toString() << " : "
        << (f1.IsGreater(f2) ? "Так" : "Ні") << endl;
    cout << f1.toString() << " < " << f2.toString() << " : "
        << (f1.IsLess(f2) ? "Так" : "Ні") << endl;
    cout << f1.toString() << " >= " << f2.toString() << " : "
        << (f1.IsGreaterOrEqual(f2) ? "Так" : "Ні") << endl;
    cout << f1.toString() << " <= " << f2.toString() << " : "
        << (f1.IsLessOrEqual(f2) ? "Так" : "Ні") << endl;

    cout << "\nДякуємо за використання програми!" << endl;

    return 0;
}