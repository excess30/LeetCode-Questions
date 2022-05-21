class Solution {
public:
    
    void generatePermutations(set<vector<int>>& s,int idx,vector<int>& nums)
    {
        if(idx==nums.size())
        {
            s.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            generatePermutations(s,idx+1,nums);
            swap(nums[idx],nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        set<vector<int>>s;
        generatePermutations(s,0,nums);
        vector<vector<int>>ans;
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};