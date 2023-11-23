#include <iostream>

using namespace std;

int main()
{
    int first[100] {0};
    int second[100] {0};
    int third[101] {0};
    int i; 
    int varik;

    for (i = 0; i < 100; ++i) {
        cout << "enter first number" << endl;
        cin >> first[i];
    }

    for (i = 0; i < 100; ++i) {
        cout << "enter second number" << endl;
        cin >> second[i];
    }
    
    cout << "chose your variant(1 if plus, 2 if minus)" << endl;
    cin >> varik;

    if (varik == 1) 
        for (i = 0; i < 1; i++) {
            *third = *first + *second;
            cout << *third << endl;
        }
    else if (varik == 2)
        for (i = 0; i < 1; i++) {
            *third = *first - *second;
            cout << *third << endl;
        }
    else
            cout << "incorect enter";
}
