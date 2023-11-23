class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.length;
        for (int a = 0; a < strs[0].length(); a++) {
            for (int b = 1; b < len; b++) {
                if (strs[b].length() <= a or strs[b].charAt(a) != strs[0].charAt(a)) {
                    return strs[0].substring(0, a);
                }
            }
        }
        return strs[0];
    }
};
