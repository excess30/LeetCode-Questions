class Solution {
public:
    
    int dfs(vector<vector<int>>&grid,int i, int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0||grid[i][j]==-1)
        {
            return 0;
        }
        grid[i][j]=-1;
        int area = 1+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int area=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    area=max(area,dfs(grid,i,j));
                }
            }
        }
        return area;
    }
};