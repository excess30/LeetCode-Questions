class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<2)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int currMax=0;
        for(int i=1;i<n;i++)
        {
          currMax = max((nums[i]-nums[i-1]),currMax);
        }
        return currMax;
    }
};