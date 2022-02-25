class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int>graph[numCourses];
        vector<int>indegree(numCourses,0);
        int res=0;
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            for(auto x: graph[i])
            {
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            res++;
            for(auto x:graph[curr])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        if(res==numCourses)
        {
            return true;
        }
        return false;
    }
};

  