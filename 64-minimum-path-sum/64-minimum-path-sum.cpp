class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        t[0][0]=grid[0][0];
        //For First Row
        for(int i=1;i<n;i++)
        {
            t[0][i] = t[0][i-1]+grid[0][i];
        }
        //For First Column
        for(int j=1;j<m;j++)
        {
            t[j][0]=t[j-1][0]+grid[j][0];
        }
        //Rest
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
               t[i][j]=min(t[i-1][j],t[i][j-1])+grid[i][j];  
            }
        }
        return t[m-1][n-1];
    }
};


