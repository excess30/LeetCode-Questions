class Solution {
public:
    
    int t[21][2001];
    int recCount(int idx,vector<int>&nums,int target,int sum)
    {
        if(nums.size()==idx)
        {
            return sum==target?1:0;
        }
        if(t[idx][sum+1000]!=-1)
        {
            return t[idx][sum+1000];
        }
        int cnt=0;
        cnt+=recCount(idx+1,nums,target,sum+nums[idx]);
        cnt+=recCount(idx+1,nums,target,sum-nums[idx]);
        return t[idx][sum+1000]=cnt;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        memset(t,-1,sizeof(t));
        return recCount(0,nums,target,0);
    }
};



