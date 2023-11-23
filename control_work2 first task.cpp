#include <iostream>

using namespace std;

int main() {

    int n;
    int sum = 0;

    cout << "enter number: ";
    cin >> n;

    for(int i = n+1; i < 0; i+=2) {
        sum += i;
    }

    cout << sum << endl;

    return 0;
}
