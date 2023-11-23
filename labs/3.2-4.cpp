#include <iostream>

using std::cin;
using std::cout;

int fact(int Number);

int main () {

	int Number;
 
	cout << "N = ";
	cin >> Number;
 
	if(Number >= 0)
		cout << fact(Number);
	else
		cout << "Error: N < 0";
  
	return 0;
 
}

int fact (int Number) {

	int factiroal = 1;
 
	for(int i = 1; i <= Number; ++i)
		factiroal *= i;
  
	return factiroal;
}
