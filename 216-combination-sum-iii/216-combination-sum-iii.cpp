class Solution {
public:
    
    void findNums(vector<vector<int>>& res, vector<int>& temp,vector<int>& nums, int n , int k,int idx)
    {
        if(temp.size()==k)
        {
            if(n==0)
            {
                res.push_back(temp);
            }
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            findNums(res,temp,nums,n-nums[i],k,i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>>res;
        vector<int>temp;
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        findNums(res,temp,nums,n,k,0);
        return res;
    }
};