class Solution {
public:
    
    void dfs(vector<vector<int>>& outgoing,vector<vector<int>>& graph,int src, int parent, int& ans, vector<bool>& vis)
    {
        vis[src]=true;
        if(parent!=-1)
        {
            if(find(outgoing[src].begin(),outgoing[src].end(),parent)==outgoing[src].end())
            {
                ans++;
            }
        }
        for(auto x:graph[src])
        {
            if(!vis[x])
            {
                dfs(outgoing,graph,x,src,ans,vis);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        int ans=0;
        vector<vector<int>>graph(n);
        vector<vector<int>>outgoing(n);
        vector<bool>vis(n,false);
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
            outgoing[connections[i][0]].push_back(connections[i][1]);
        }
        dfs(outgoing,graph,0,-1,ans,vis);
        return ans;
    }
};


