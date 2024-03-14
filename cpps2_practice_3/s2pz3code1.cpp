#include <iostream>
#include <iomanip> // Для налаштування виведення чисел з плаваючою крапкою

using namespace std;

int main() {
    int size;

    // Запит користувача на введення розміру масиву
    cout << "Введіть розмір масиву: ";
    cin >> size;

    // Динамічне виділення пам'яті для масиву
    float *array = new float[size];

    // Заповнення масиву випадковими числами з плаваючою крапкою в діапазоні (-2, 2)
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<float>(rand()) / (RAND_MAX / 4.0) - 2.0; // Випадкове число від -2 до 2
        array[i] = roundf(array[i] * 10) / 10; // Округлення до 1 знака після крапки
    }

    // Виведення масиву у консоль
    cout << "Масив: ";
    for (int i = 0; i < size; ++i) {
        cout << fixed << setprecision(1) << array[i] << " ";
    }
    cout << endl;

    // Підрахунок кількості додатних та від'ємних чисел
    int positiveCount = 0, negativeCount = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            positiveCount++;
        } else if (array[i] < 0) {
            negativeCount++;
        }
    }

    // Виведення кількості додатних та від'ємних чисел
    cout << "Кількість додатних чисел: " << positiveCount << endl;
    cout << "Кількість від'ємних чисел: " << negativeCount << endl;

    // Звільнення пам'яті
    delete[] array;

    return 0;
}
