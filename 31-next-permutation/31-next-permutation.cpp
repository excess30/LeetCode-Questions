class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int bp=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                bp=i-1;
                break;
            }
        }
        if(bp<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[bp])
            {
                swap(nums[i],nums[bp]);
                reverse(nums.begin()+bp+1,nums.end());
                break;
            }
        }
    }
};


