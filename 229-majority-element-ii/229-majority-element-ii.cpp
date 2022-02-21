class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int>res;
        unordered_map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        for(auto y:mp)
        {
            if(y.second>nums.size()/3)
            {
                res.push_back(y.first);
            }
        }
        return res;
    }
};