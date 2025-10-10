#include <iostream>
#include <bitset>  

/*Вариант 3
1. Если i бит А не равен 0 – Ввести два целых числа, если одно из них кратно другому, 
вывести результат деления, иначе вывести их произведение. Иначе – установить значения 
i+1 и i-1 битов на противоположные, показать результат. 

2. Ввести с клавиатуры N – номер ошибки, с помощью switch вывести её описание. 
Предусмотреть обработку ошибочного ввода N.*/

int main() {

    // пункт 1
    short A;
    int i; 
    std::cout << "Please enter A, i" <<std::endl;
    if (!(std::cin >> A >> i)) { // проверяем, чтобы на ввод были поданы именно цифры, а не другие символы
        std::cout<<"Wrong input\n";
        return 0;
    }
    if (i < 0 || i > 7) {
        std::cout<<"Wrong input\n";
        return 0;
    }

    
    int bit_i = (A >> i) & 1;
    std::cout << "i-bit of A is (" << i << "): " << bit_i << "\n";

    if (bit_i != 0) {
        int x, y;
        std::cout <<"Enter x and y"<<std::endl;
        if(!(std::cin >> x >> y)) {
           std::cout<<"Wrong input\n";
            return 0; 
        } else {
            if ((y != 0) && (x % y == 0)) {
                float div = (float)x / y;
                std::cout << "x / y = " << std::bitset<8>(div) <<std::endl;
            }
            if ((x != 0) && (y % x == 0)) {
                float div = (float)y / x;
                std::cout << "y / x = " << std::bitset<8>(div) <<std::endl;
            }
            else if (((x != 0) && (y % x != 0)) || (y != 0) && (x % y != 0)) {
                std::cout << "x * y = " << std::bitset<8>(x*y)<<std::endl;
            }
        }
    } else {
        short result = A; // задаём отдельную переменную для сохранения инвертированного вида
        if (i > 0) {
            result ^= (1 << (i - 1)); // вызываем xor и сразу сохраняем результат в result
        }
        if (i < 7) {
            result ^= (1 << (i + 1));
        }
        std::cout << "Before: " << std::bitset<sizeof(int)*8>(A) << std::endl;
        std::cout << "After: " << std::bitset<sizeof(int)*8>(result) << std::endl;

    }

    // пункт 2: switch по коду ошибки
    std::cout << "Enter N: ";
    int N;
    if (!(std::cin >> N)) {
        std::cout << "Wrong input" << std::endl;
        return 0;
    }

    std::cout << "Error code N: " << N << " " << std::bitset<8>(N) << std::endl;
    switch (N) {
        case 1: std::cout << "Injection ECU malfunction\n"; break;
        case 2: std::cout << "Fuel level sensor malfunction\n"; break;
        case 4: std::cout << "Overvoltage\n"; break;
        case 8: std::cout << "Undervoltage\n"; break;
        case 13: std::cout << "No oxygen sensor signal\n"; break;
        case 51: std::cout << "ROM malfunction\n"; break;
        case 52: std::cout << "RAM malfunction\n"; break;
        case 55: std::cout << "Too lean air-fuel mixture\n"; break;
        case 61: std::cout << "Oxygen sensor malfunction\n"; break;
        default: std::cout << "Unknown error code\n"; break;
    }

    return 0;
}