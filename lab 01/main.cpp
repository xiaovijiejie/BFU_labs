#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// используем int
/*в задании нужны целые числа
по условию числа неотрицательные, однако в результате вычитания могут образоваться отрицательные*/
int main() {
    setlocale(LC_ALL, "Russian");

    int a;
    int b;

    std::cin >> a >> b;

    cout<<"int занимает" << sizeof(int)*8 << "бит" << "\n";
    cout<<"Min значение" << INT_MIN << "\n";
    cout<<"Max значение" << INT_MAX << "\n";

    int sum = a + b;
    int diff_1 = a - b;
    int diff_2 = b - a;
    int mult = a*b;
    int div_1 = a / b;
    int div_2 = b / a;
    std::cout << "Результаты операций"<<"\n";
    std::cout << "сложение: "     << sum     << "\n";
    std::cout << "вычитание a - b: " << diff_1 << "\n";
    std::cout << "вычитание b - a: " << diff_2 << "\n";
    std::cout << "умножение: "    << mult    << "\n";
    std::cout << "деление a / b: "    << div_1    << "\n";
    std::cout << "деление b / a: "    << div_2    << "\n";

    return 0;
}