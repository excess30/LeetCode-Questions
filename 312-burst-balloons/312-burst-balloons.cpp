class Solution {
public:
    
    int t[502][502];
    int maxValue(vector<int>& nums,int i ,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        int finalAns = INT_MIN;
        for(int k=i;k<j;k++)
        {
            int lSum = maxValue(nums,i,k);
            int rSum = maxValue(nums,k+1,j);
            int temp = lSum+rSum+nums[i-1]*nums[k]*nums[j];
            finalAns=max(finalAns,temp);
        }
        return t[i][j]=finalAns;
    }
    
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        memset(t,-1,sizeof(t));
        return maxValue(nums,1,nums.size()-1);
    }
};


