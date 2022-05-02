class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>odd;
        vector<int>even;
        vector<int>finalV;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                even.push_back(nums[i]);
            }
            else
            {
                odd.push_back(nums[i]);
            }
        }
        for(auto x:even)
        {
            finalV.push_back(x);
        }
        for(auto y:odd)
        {
            finalV.push_back(y);
        }
        return finalV;
    }
};