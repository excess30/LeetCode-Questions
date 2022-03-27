class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            t[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    t[i][j]=matrix[i][j]+min(t[i-1][j],t[i-1][j+1]);
                }
                else if(j==n-1)
                {
                     t[i][j] = matrix[i][j] +min(t[i-1][j-1],t[i-1][j]);
                }
                else
                {
                     t[i][j]=matrix[i][j]+min(t[i-1][j-1],min(t[i-1][j],t[i-1][j+1]));
                }
            }
        }
        int minm=INT_MAX;
        for(int i=0;i<m;i++)
        {
            if(t[m-1][i]<minm)
            {
                minm=t[m-1][i];
            }
        }
        return minm;
    }
};


 