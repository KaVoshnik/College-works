class Solution {
public:
    vector <int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        for (int a = 0; a < nums.size() - 1; a++) {
            for (int b = 0; b < nums.size() - 1; b++) {
                if (nums[a] + nums[b] == target) { 
                    if(result.empty()){result.push_back(a); result.push_back(b);}
                    else {result[0] = a; result[1]= b; }
                }
            }
        }
        return result;
    }
};
