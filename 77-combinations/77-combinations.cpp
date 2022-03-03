class Solution {
public:
    
    void combinations(int n, int k, int idx,vector<vector<int>>& nums,vector<int>& path)
    {
        if(path.size()==k)
        {
            nums.push_back(path);
            return;
        }
       for(int i=idx;i<n;i++)
        {
            path.push_back(i+1);
            combinations(n,k,i+1,nums,path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>nums;
        vector<int>path;
        combinations(n,k,0,nums,path);
        return nums;
    }
};



