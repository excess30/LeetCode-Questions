class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        int ans=nums[0];
        int maxm=ans;
        int minm=ans;
        for(int i=1;i<n;i++)
        {
           if(nums[i]<0)
           {
               swap(maxm,minm);
           }
            maxm=max(nums[i],maxm*nums[i]);
            minm=min(nums[i],minm*nums[i]);
            ans=max(ans,maxm);
        }
        return ans;
    }
};

 