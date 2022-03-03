class Solution {
public:
    
    void generateSubs(vector<int>& nums, vector<int>& path, set<vector<int>>& res, int idx)
    {
        if(idx==nums.size())
        {
            res.insert(path);
            return;
        }
        path.push_back(nums[idx]);
        generateSubs(nums,path,res,idx+1);
        path.pop_back();
        generateSubs(nums,path,res,idx+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int>path;
        set<vector<int>>res;
        vector<vector<int>>subset;
        generateSubs(nums,path,res,0);
        for(auto x:res)
        {
            subset.push_back(x);
        }
        return subset;
    }
};