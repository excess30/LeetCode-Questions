class Solution {
public:
    
    void generateSubs(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, int idx)
    {
        if(idx==nums.size())
        {
            res.push_back(path);
            return;
        }
        path.push_back(nums[idx]);
        generateSubs(nums,path,res,idx+1);
        path.pop_back();
        generateSubs(nums,path,res,idx+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int>path;
        vector<vector<int>>res;
        generateSubs(nums,path,res,0);
        return res;
    }
};