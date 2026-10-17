class Solution {
public:
 
        long long count_digit(int  num)
        {
            long long sum=0;
            while(num>0)
            {
                sum+=num%10;
                num/=10;
            }
            return sum;
        }
    int minSwaps(vector<int>& nums) {

        //algo is first find the count of number 
        vector<int>nums2=nums;
        auto lambda =[&](int num1, int num2)
        {
            int digitcount1=count_digit(num1);
            int digitcount2=count_digit(num2);
            if(digitcount1!=digitcount2)
            {
                return digitcount1<digitcount2;
            }
           
                return num1<num2;

        };
        sort(nums2.begin(), nums2.end(), lambda);
       
        unordered_map<int,int>map;
        for(int i=0; i<nums.size(); i++)
        {
           // cout<<nums2[i]<<" ";
            map[nums[i]]=i;
        }
        int count=0;
        // cout<<endl;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=nums2[i])
            {
                int find=map[nums2[i]];
                nums[find]=nums[i];
                nums[i]=nums2[i];
                map[nums[i]]=i;
                map[nums[find]]=find;
            
                count++;
            }
        }
       
        return count;

        

    }
};