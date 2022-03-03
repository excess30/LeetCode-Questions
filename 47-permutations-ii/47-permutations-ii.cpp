class Solution {
public:
    
    void permute(vector<int>& nums, set<vector<int>>& s, int idx)
    {
        if(idx==nums.size())
        {
            s.insert(nums);
            return;
        }
        for(int i= idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            permute(nums,s,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        set<vector<int>>s;
        permute(nums,s,0);
        vector<vector<int>>res;
        for(auto x:s)
        {
            res.push_back(x);
        }
        return res;
    }
};