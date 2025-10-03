#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// используем int
/*в задании нужны целые числа
по условию числа неотрицательные, однако в результате вычитания могут образоваться отрицательные*/
/*так как в результате деления может выйти не целый результат, требуется сохранить соответствующие
переменные в нецелочисленном типе float. Занимает столько же памяти, сколько и int (4 байта)*/
int main() {
    setlocale(LC_ALL, "Russian");

    int a;
    int b;

    std::cin >> a >> b;

    cout<<"int занимает" << sizeof(int)*8 << " бит" << "\n";
    cout<<"MIN значение int" << INT_MIN << "\n";
    cout<<"MAX значение int" << INT_MAX << "\n";
    cout<<"float занимает" << sizeof(float) * 8 << " бит" << "\n";
    cout<<"MIN значение float" << numeric_limits<float>::lowest() << "\n";
    cout<<"MAX значение float" << numeric_limits<float>::max() << "\n";

    int sum = a + b;
    int diff_1 = a - b;
    int diff_2 = b - a;
    int mult = a*b;
    float div_1 = (float)a / b;
    float div_2 = (float)b / a;
    std::wcout << L"Результаты операций"<<"\n";
    std::cout << "сложение: "     << sum     << "\n";
    std::cout << "вычитание a - b: " << diff_1 << "\n";
    std::cout << "вычитание b - a: " << diff_2 << "\n";
    std::cout << "умножение: "    << mult    << "\n";
    std::cout << "деление a / b: "    << div_1    << "\n";
    std::cout << "деление b / a: "    << div_2    << "\n";

    return 0;
}