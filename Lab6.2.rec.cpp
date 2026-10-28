// Lab 6.2 (recursive)
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(const int* a, const int size, int i);
bool IsOdd(const int x);
int CountOdd(const int* a, const int size, int i);

int main()
{
    srand((unsigned)time(NULL));  // ініціалізація генератора випадкових чисел

    const int n = 20;              // кількість елементів масиву
    int a[n];

    const int Low = -20;           // нижня межа діапазону значень
    const int High = 20;           // верхня межа діапазону значень

    Create(a, n, Low, High, 0);
    cout << "Array:" << endl;
    Print(a, n, 0);

    cout << "Count of odd elements = " << CountOdd(a, n, 0) << endl;

    return 0;
}

// формування масиву випадковими числами з [Low; High]
void Create(int* a, const int size, const int Low, const int High, int i)
{
    if (i < size)
    {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

// виведення масиву в рядок
void Print(const int* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    }
    else
        cout << endl;
}

// перевірка, чи число непарне
bool IsOdd(const int x)
{
    return x % 2 != 0;
}

// обчислення кількості непарних елементів масиву
int CountOdd(const int* a, const int size, int i)
{
    if (i < size)
    {
        if (IsOdd(a[i]))
            return 1 + CountOdd(a, size, i + 1);
        else
            return CountOdd(a, size, i + 1);
    }
    else
        return 0;
}
