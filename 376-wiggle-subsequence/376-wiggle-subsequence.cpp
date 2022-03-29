class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<2)
        {
            return n;
        }
        int cnt=0;
        int prev = nums[1]-nums[0];
        if(prev==0)
        {
            cnt=1;
        }
        else
        {
            cnt=2;
        }
        for(int i=2;i<nums.size();i++)
        {
            int next = nums[i]-nums[i-1];
            if((next<0 && prev>=0) ||(next>0 && prev<=0))
            {
                cnt++;
                prev=next;
            }
        }
        return cnt;
    }
};