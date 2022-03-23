class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int maxm=0,sum=0;
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=0;j<accounts[0].size();j++)
            {
                 sum+=accounts[i][j];
            }
            maxm=max(maxm,sum);
            sum=0;
        }
        return maxm;
    }
};