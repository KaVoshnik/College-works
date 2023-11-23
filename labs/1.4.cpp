#include <iostream>

using namespace std;

int main() {

int v0,t,v;
const double g = 9.81;

cout << "input v0: "; cin >> v0;
cout << "input t: "; cin >> t;

v = v0 - g * t;

cout << "v0 - g * t = " << v;

}
