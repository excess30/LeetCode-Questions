class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int cnt=0;
        int n = nums.size();
        if(n<3)
        {
            return 0;
        }
        int ans=0;
        int prev = nums[1]-nums[0];
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==prev)
            {
                cnt++;
            }
            else
            {
                prev=nums[i]-nums[i-1];
                cnt=0;
            }
            ans+=cnt;
        }
        return ans;
    }
};