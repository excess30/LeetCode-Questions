class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& res, vector<int>& path,int src,int dest)
    {
        path.push_back(src);
        if(src==dest)
        {
            res.push_back(path);
        }
        for(auto x:graph[src])
        {
            dfs(graph,res,path,x,dest);
        }
        path.pop_back();
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>>res;
        vector<int>path;
        dfs(graph,res,path,0,n-1);
        return res;
    }
};