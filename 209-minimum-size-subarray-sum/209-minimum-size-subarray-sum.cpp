class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int ans = INT_MAX;
        int i=0,j=0,sum=0;
        while(j<n)
        {
            sum+=nums[j++];
            while(sum>=target)
            {
                ans=min(ans,j-i);
                sum-=nums[i++];
            }
        }
        if(ans==INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};