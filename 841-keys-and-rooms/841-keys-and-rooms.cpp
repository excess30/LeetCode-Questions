class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int> &vis, int i){
        vis[i]=1;
        for(auto u : rooms[i]){
            if(!vis[u])
                dfs(rooms, vis, u);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        dfs(rooms, vis, 0);
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0)
                return false;
        }
        return true;
    }
};