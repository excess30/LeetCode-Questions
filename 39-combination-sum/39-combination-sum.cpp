class Solution {
public:
    void combinations(vector<int>& candidates,int idx,vector<vector<int>>& res,vector<int>& curr,int target)
    {
        if(idx==candidates.size())
        {
            if(target==0)
            {
                 res.push_back(curr);
            }
            return;
        }
        if(candidates[idx]<=target)
        {
            curr.push_back(candidates[idx]);
            combinations(candidates,idx,res,curr,target-candidates[idx]);
            curr.pop_back();
        }
        combinations(candidates,idx+1,res,curr,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>res;
        vector<int>curr;
        combinations(candidates,0,res,curr,target);
        return res;
    }
};

