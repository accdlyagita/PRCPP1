#include <iostream>
using namespace std;

int main(void) {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]);

    // Ініціалізуємо вказівник на перший елемент масиву
    int *min_ptr = &vector[0];

    // Проходимося по всіх елементах масиву за допомогою вказівника і знаходимо найменший елемент
    for (int *ptr = &vector[1]; ptr < &vector[n]; ptr++) {
        if (*ptr < *min_ptr) {
            min_ptr = ptr; // Оновлюємо вказівник на найменший елемент
        }
    }

    // Виводимо найменший елемент
    cout << "Найменший елемент масиву: " << *min_ptr << endl;

    return 0;
}
