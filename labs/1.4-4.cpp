#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int n,R;
    
    cin >> n >> R;
    
    double z=180/n; 
    double c=sin(z);
    double i=abs(c);
    
    int An=2*R*i;
    int P=An*n;
    
    double S=1.0/2*P*R;
    
    printf("%.2lf", S);
    
    return 0;
}
