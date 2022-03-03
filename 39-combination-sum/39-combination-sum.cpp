class Solution {
public:
    
    void combinations(vector<int>& candidates,int target,vector<int>& path,vector<vector<int>>& res, int idx)
    {
        if(idx==candidates.size())
        {
            if(target==0)
            {
                res.push_back(path);
            }
            return;
        }
        if(candidates[idx]<=target)
        {
            path.push_back(candidates[idx]);
            combinations(candidates,target-candidates[idx],path,res,idx);
            path.pop_back();
        }
            combinations(candidates,target,path,res,idx+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>path;
        vector<vector<int>>res;
        combinations(candidates,target,path,res,0);
        return res;
    }
};