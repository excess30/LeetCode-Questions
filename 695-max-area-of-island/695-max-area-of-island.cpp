class Solution {
public:
    
    int findIslands(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)
        {
            return 0;
        }
        grid[i][j]=0;
        int area = 1+findIslands(grid,i+1,j)+findIslands(grid,i-1,j)+findIslands(grid,i,j+1)+findIslands(grid,i,j-1);
        return area;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int area = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    area=max(area,findIslands(grid,i,j));
                }
            }
        }
        return area;
    }
};