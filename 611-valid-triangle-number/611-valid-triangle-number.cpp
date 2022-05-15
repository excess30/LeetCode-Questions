class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        int cnt=0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=n-1;i>=0;i--)
        {
            int l=0,r=i-1;
            while(l<r)
            {
                if(nums[l]+nums[r]>nums[i])
                {
                    cnt+=r-l;
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return cnt;
    }
};