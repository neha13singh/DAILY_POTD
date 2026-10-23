class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                result &= nums[i];
            }
        }

        return result == -1 ? 0 : result;
    }
};