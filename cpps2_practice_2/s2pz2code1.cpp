#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int size = 5; // Розмір двовимірного масиву
    int matrix[size][size]; // Оголошення двовимірного масиву
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    // Заповнення масиву випадковими значеннями
    for (int *ptr = &matrix[0][0]; ptr < &matrix[size][size]; ptr++) {
        *ptr = rand() % 100; // Генеруємо випадкове число в діапазоні [0, 99]
    }

    // Виведення елементів на головній діагоналі
    cout << "Елементи на головній діагоналі: ";
    for (int i = 0; i < size; i++) {
        cout << *(*(matrix + i) + i) << " "; // Використовуємо вказівники для доступу до елементів
    }
    cout << endl;

    // Виведення елементів на побічній діагоналі
    cout << "Елементи на побічній діагоналі: ";
    for (int i = 0; i < size; i++) {
        cout << *(*(matrix + i) + (size - 1 - i)) << " "; // Використовуємо вказівники для доступу до елементів
    }
    cout << endl;

    // Підрахунок кількості парних та непарних елементів
    int evenCount = 0, oddCount = 0;
    for (int *ptr = &matrix[0][0]; ptr < &matrix[size][size]; ptr++) {
        if (*ptr % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    // Виведення кількості парних та непарних елементів
    cout << "Кількість парних елементів: " << evenCount << endl;
    cout << "Кількість непарних елементів: " << oddCount << endl;

    return 0;
}
