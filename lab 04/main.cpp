#include <iostream>

/*Л4
В пункте 1, размер массива равен №варианта + 3.
В пункте 2, матрицы формата 3 строки х 4 столбца.
Числа вводятся корректно и все они типа int. Из нескольких одинаковых значений выбирать первое.

Вариант 3
1. Упорядочить массив по возрастанию, если есть пара одинаковых чисел подряд.
2. Найти строку с наибольшей суммой модулей элементов и обнулить её значения.
*/

int main() {
    // Пункт 1
    const int VAR = 3;
    const int N = VAR + 3; // размер массива по условию
    int a[N];

    std::cout << "Enter " << N << " integers for the array:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    // Проверяем наличие соседней пары равных элементов
    bool has_adj_equal = false;
    for (int i = 0; i + 1 < N; ++i) {
        if (a[i] == a[i + 1]) {
            has_adj_equal = true;
            break;
        }
    }

    if (has_adj_equal) {
        bool swapped = true;       
        while (swapped) {
            swapped = false;
            for (int i = 0; i + 1 < N; ++i) {
                if (a[i] > a[i + 1]) {
                    int tmp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = tmp;
                    swapped = true;
                }
            }
        }
        std::cout << "Array had adjacent equals -> sorted ascending:\n";
    } else {
        std::cout << "No adjacent equal pair -> array unchanged:\n";
    }

    for (int i = 0; i < N; ++i) {
        std::cout << a[i] << (i + 1 == N ? '\n' : ' ');
    }


    // Пункт 2
    const int R = 3; // строки
    const int C = 4; // столбцы
    int m[R][C];

    std::cout << "\nEnter 3x4 matrix of integers (" << R << " rows, " << C << " columns):\n";
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> m[i][j];
        }
    }

    int maxRow = 0; 
    int maxSum = 0;

    // Сначала посчитаем для строки 0, чтобы инициализировать maxSum
    for (int j = 0; j < C; ++j) {
        maxSum += std::abs(m[0][j]);
    }

    // Сравниваем остальные строки
    for (int i = 1; i < R; ++i) {
        int curSum = 0;
        for (int j = 0; j < C; ++j) {
            curSum += std::abs(m[i][j]);
        }
        if (curSum > maxSum) {
            maxSum = curSum;
            maxRow = i; // при равенстве НЕ меняем — так выбирается первая
        }
    }

    // Обнуляем найденную строку
    for (int j = 0; j < C; ++j) {
        m[maxRow][j] = 0;
    }

    std::cout << "Row with max |sum| = " << (maxRow + 1) << ". Zeroed matrix:\n";
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << m[i][j] << (j + 1 == C ? '\n' : ' ');
        }
    }

    return 0;
}