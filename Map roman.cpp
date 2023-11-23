#include <iostream> 
#include <map> 

int romanToInt(std::string s) {

    std::map<char, int> romanValues = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

    int result = 0;
    int prevValue = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        int currValue = romanValues[s[i]];

        if (currValue >= prevValue) {
            result += currValue;
        }
        else {
            result -= currValue;
        }

        prevValue = currValue;
    }

    return result;
}

int main() {
    std::string romanNumeral;
    std::cout << "Введите число:" << std::endl;
    std::cin >> romanNumeral;
    int intValue = romanToInt(romanNumeral);

    std::cout << "Roman Numeral: " << romanNumeral << std::endl;
    std::cout << "Integer Value: " << intValue << std::endl;

    return 0;
}
