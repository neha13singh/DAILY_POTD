/*
Intuition:
1. I just followed brute force, talked about three values so take three loops
2.we need different indexed so add filter that these three indexed needs not to same.
3.checked last value as we need even number and checked first number as it can't be zero.
4.we need unique numbers to identify unique number either i can convert these three digits to number 
or to string and then add to set to find only unique values.
5. I chose to convert them into strings.

Complexity is O(n^3) time complexity and O(n) space complexity.
space complexity is O(n) because i am using set to store strings.

Better Approach :The limit is upto 10 only we can simply iterate from 0 to 10 from all theee loops
and then did the same work and for values like 0 to 10 we can use unordered_map or vector for storing occurances. we need not to use unique thing because it is not going to repeat in this way.

*/

class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        //three loops
        int n=nums.size();
        int count=0;
        set<string>st;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
              
                for(int k=0; k<n; k++)
                {
                   if(i!=j && j!=k && i!=k)
                   {
                    if(nums[k]%2==0  && nums[i]!=0)
                    {
                        count++;
                        string str=to_string(nums[i])+to_string(nums[j])+to_string(nums[k]);
                        cout<<str<<endl;
                        st.insert(str);
                    }
                   }
                }
            }
        }
        return st.size();
        return count;
    }
};