class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    grid[i][j]=-1;
                }
            }
        }
        while(q.empty()==false)
        {
            cnt++;
            int sz=q.size();
            while(sz--)
            {
                auto i = q.front().first;
                auto j = q.front().second;
                q.pop();
                if(i-1>=0 && grid[i-1][j]==0)
                {
                    q.push({i-1,j});
                    grid[i-1][j]=-1;
                }
                if(i+1<n && grid[i+1][j]==0)
                {
                    q.push({i+1,j});
                    grid[i+1][j]=-1;
                }
                if(j-1>=0 && grid[i][j-1]==0)
                {
                    q.push({i,j-1});
                    grid[i][j-1]=-1;
                }
                if(j+1<m && grid[i][j+1]==0)
                {
                    q.push({i,j+1});
                    grid[i][j+1]=-1;
                }
            }
        }
        return cnt>1?cnt-1:-1;
    }
};