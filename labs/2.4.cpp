#include <math.h>
#include <iostream>

using namespace std;

int main() {

    double ax, bx, ay, by;
    
cout << "input a: "; cin >> ax >> ay;
cout << "input b: "; cin >> bx >> by;
cout << "ax * bx + ay * by / sqrt(pow(ax,2) + pow(ay,2)) * sqrt(pow(bx,2) + pow(by,2)) = " <<  cos((ax * bx + ay * by)/(sqrt(pow(ax,2) + pow(ay,2)) * sqrt(pow(bx,2) + pow(by,2))));

return 0;

}
