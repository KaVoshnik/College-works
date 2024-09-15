#include <iostream>
#include <algorithm>

int main()
{

    int arr[10]; // создали массив на 10 элементов
    int key;     // создали переменную в которой будет находиться ключ

    std::cout << "enter 10 number for massive: " << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cin >> arr[i]; // считываем элементы массива
    }

    std::sort(arr, arr + 10); // сортируем с помощью функции sort (быстрая сортировка)

    std::cout << "enter key: " << std::endl;

    std::cin >> key; // считываем ключ

    bool flag = false;
    int l = 0; // левая граница
    int r = 9; // правая граница
    int mid;

    while ((l <= r) && (flag != true))
    {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (arr[mid] == key)
            flag = true; // проверяем ключ со серединным элементом
        if (arr[mid] > key)
            r = mid - 1; // проверяем, какую часть нужно отбросить
        else
            l = mid + 1;
    }

    if (flag)
        std::cout << "element index " << key << " in massive = " << mid << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}
