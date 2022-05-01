class Solution {
public:
    
    int bfs(vector<vector<int>>&grid)
    {
        queue<vector<int>>q;
        q.push({0,0,0});
        while(q.empty()==false)
        {
            auto t = q.front();
            auto i = t[0];
            auto j = t[1];
            q.pop();
            if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==1)
            {
               continue;
            }
            if(i==grid.size()-1 && j==grid[0].size()-1)
            {
                return t[2]+1;
            }
            if(grid[i][j]==0)
            {
                grid[i][j]=1;
                q.push({i+1,j,t[2]+1});
                q.push({i-1,j,t[2]+1});
                q.push({i,j+1,t[2]+1});
                q.push({i,j-1,t[2]+1});
                q.push({i+1,j+1,t[2]+1});
                q.push({i+1,j-1,t[2]+1});
                q.push({i-1,j+1,t[2]+1});
                q.push({i-1,j-1,t[2]+1}); 
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
        {
            return -1;
        }
        return bfs(grid);
    }
};