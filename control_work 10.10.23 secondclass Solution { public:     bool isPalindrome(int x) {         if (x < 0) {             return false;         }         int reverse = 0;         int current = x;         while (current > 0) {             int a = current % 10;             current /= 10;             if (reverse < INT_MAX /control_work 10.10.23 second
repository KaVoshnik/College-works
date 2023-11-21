class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int reverse = 0;
        int current = x;
        while (current > 0) {
            int a = current % 10;
            current /= 10;
            if (reverse < INT_MAX / 10 || (reverse == INT_MAX % 10 && a <= INT_MAX % 10)) {
                reverse - reverse * 10 + a;
            }
            else {
                return false;
            }
        }
        return reverse == x;
    }
};
