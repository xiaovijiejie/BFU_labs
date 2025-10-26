#include <iostream>


/*Для пункта 1 последовательность целых чисел {A1, A2, …, AN} 
вводим с клавиатуры. Числа последовательности хранить не нужно. 
Количество чисел в последовательности вводится с клавиатуры (корректно). 
Если в последовательности нет чисел, удовлетворяющих условию, вывести сообщение о состоянии.

Для пункта 2 ввести целое  |X| <1.000 и для него посчитать по заданию.*/

/*Вариант 3

1. Числа вещественные. Найти сумму всех чисел из интервала (-0,36; 10,1], 
наибольшее из таких чисел и его номер в последовательности.
2. Найти произведение цифр числа.
 */
int main () {
    // пункт 1

    int N;
    std::cout << "Enter the number of elements\n";
    std::cin >> N;
    if (N <= 0) {
        std::cout << "Wrong input\n";
        return 0;
    }
    
    double sum = 0.0;
    double maxVal = 0.0;
    int maxIndex = -1;
    bool found = false;

    for (int i = 1; i <= N; ++i) {
        double x;
        std::cout << "Enter number " << i << ": ";
        std::cin >> x;
        if (!(x > -0.36 && x <= 10.1)) {
            continue;
        }

        sum +=x;
        if (!found || x > maxVal) {
            maxVal = x;
            maxIndex = i;
            found = true;    
        }
    }
    if (!found) {
            std::cout << "No numbers in (-0.36; 10.1].\n";
        }
        else {
            std::cout << "sum = " << sum << std::endl;
            std::cout << "Max = " << maxVal << ", index = " << maxIndex << std::endl;
        }

    //пункт 2

    int X;
    std::cout << "Enter integer X (|X| < 1000)\n";
    if (!(std::cin >> X) || std::abs(X) >= 1000) {
        std::cout << "Wrong input.\n";
        return 0;
    }

    int t = std::abs(X);
    int prod = 1;

    if (t == 0) {
        prod = 0;
    } else {
        do {
            int digit = t % 10;
            prod *= digit;
            t /= 10;
        } while (t > 0);
    }
    std::cout << "Product of digits = " << prod << std::endl;
    return 0;
}