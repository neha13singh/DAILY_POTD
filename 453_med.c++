class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            mini=min(mini,nums[i]);
        }
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            count+=nums[i]-mini;
        }
        return count;
    }
};