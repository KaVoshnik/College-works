#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<int> arr;
   int num; 
   do {
      cin >> num; 
      if (num != -1) 
         arr.push_back(num);
   } while (num != -1);

   int sum = 0;
   for (int i = 0; i < arr.size(); i++) { 
      sum += arr[i];
   }
   cout << "Summ numbers: " << sum << endl;
   
   return 0;
}
