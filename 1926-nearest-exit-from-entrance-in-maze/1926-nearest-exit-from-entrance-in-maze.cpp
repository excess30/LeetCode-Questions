class Solution {
public:
    
    int bfs(vector<vector<char>>& maze,vector<int>& entrance)
    {
        int sourceRow=entrance[0];
        int sourceCol=entrance[1];
        queue<vector<int>>q;
        q.push({sourceRow,sourceCol,0});
        while(q.empty()==false)
        {
            int sz = q.size();
            while(sz--)
            {
                auto t = q.front();
                int x = t[0];
                int y = t[1];
                q.pop();
                if(x<0||x>=maze.size()||y<0||y>=maze[0].size()||maze[x][y]=='+')
                {
                    continue;
                }
                if(x==0||y==0||x==maze.size()-1||y==maze[0].size()-1)
                {
                    if(maze[x][y]!=maze[sourceRow][sourceCol])
                    {
                        return t[2];
                    } 
                }
                    maze[x][y]='+';
                    q.push({x+1,y,t[2]+1});
                    q.push({x-1,y,t[2]+1});
                    q.push({x,y+1,t[2]+1});
                    q.push({x,y-1,t[2]+1});
            }
        }
        return -1;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
       return bfs(maze,entrance);
    }
};