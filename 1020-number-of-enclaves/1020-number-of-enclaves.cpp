class Solution {
public:
    
    void search(vector<vector<int>>& grid,int i, int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)
        {
            return;
        }
        grid[i][j]=0;
        search(grid,i+1,j);
        search(grid,i-1,j);
        search(grid,i,j+1);
        search(grid,i,j-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<n;i++)
        {
            search(grid,0,i);
            search(grid,m-1,i);
        }
        for(int i=0;i<m;i++)
        {
            search(grid,i,0);
            search(grid,i,n-1);
        }
        int cnt=0;
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