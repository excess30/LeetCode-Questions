class Solution {
public:
    
    int bfs(vector<vector<int>>& grid)
    {
        queue<vector<int>>q;
        q.push({0,0,0});
        while(q.empty()==false)
        {
            auto t = q.front();
            auto x = t[0];
            auto y = t[1];
            q.pop();
            if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]==1)
            {
                continue;
            }
            if(x==grid.size()-1 && y==grid[0].size()-1)
            {
                return t[2]+1;
            }
            if(grid[x][y]==0)
            {
                grid[x][y]=1;
                q.push({x+1,y,t[2]+1});
                q.push({x-1,y,t[2]+1});
                q.push({x,y+1,t[2]+1});
                q.push({x,y-1,t[2]+1});
                q.push({x-1,y-1,t[2]+1});
                q.push({x+1,y+1,t[2]+1});
                q.push({x-1,y+1,t[2]+1});
                q.push({x+1,y-1,t[2]+1});
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

 