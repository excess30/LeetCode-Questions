class Solution {
public:
    int minScore(vector<int>& values, int i, int j,vector<vector<int>>& t)
    {
        if(i+1==j)
        {
            return 0;
        }
        int ans = INT_MAX;
        if(t[i][j]!=0)
        {
            return t[i][j];
        }
        for(int k=i+1;k<j;k++)
        {
            int la = minScore(values,i,k,t);
            int ra = minScore(values,k,j,t);
            auto tempAns = la+(values[i]*values[k]*values[j])+ra;
            ans = min(ans,tempAns);
        }
        return t[i][j]=ans;
    }
    
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size();
        vector<vector<int>>t(n,vector<int>(n,0));
        return minScore(values,0,n-1,t);
    }
};

