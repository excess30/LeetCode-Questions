class Solution {
public:
    
    void permutation(vector<int>& nums,vector<vector<int>>& res, int idx)
    {
        if(idx==nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            permutation(nums,res,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>res;
        permutation(nums,res,0);
        return res;
    }
};