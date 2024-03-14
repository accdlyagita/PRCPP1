#include <iostream>
#include <cstdlib> // Для функції rand()
#include <ctime>   // Для функції time()

using namespace std;

int main() {
    // Встановлюємо випадкове насіння
    srand(time(0));

    // Розмірність масиву
    const int rows = 3;
    const int cols = 3;

    // Створення двовимірного динамічного масиву
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Заповнення масиву випадковими значеннями та виведення його на екран
    cout << "Двовимірний масив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100; // Випадкове число від 0 до 99
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Виведення елементів, що знаходяться на головній діагоналі
    cout << "Елементи на головній діагоналі:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << matrix[i][i] << " ";
    }
    cout << endl;

    // Виведення елементів, що знаходяться на побічній діагоналі
    cout << "Елементи на побічній діагоналі:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << matrix[i][cols - i - 1] << " ";
    }
    cout << endl;

    // Підрахунок кількості парних та непарних елементів масиву
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
    }

    // Виведення кількості парних та непарних елементів масиву
    cout << "Кількість парних елементів: " << evenCount << endl;
    cout << "Кількість непарних елементів: " << oddCount << endl;

    // Звільнення пам'яті
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
