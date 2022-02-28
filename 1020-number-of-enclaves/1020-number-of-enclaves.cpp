class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)
        {
            return;
        }
        grid[i][j]=0;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            dfs(grid,i,0);
            dfs(grid,i,n-1);
        }
        for(int i=0;i<n;i++)
        {
            dfs(grid,0,i);
            dfs(grid,m-1,i);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};