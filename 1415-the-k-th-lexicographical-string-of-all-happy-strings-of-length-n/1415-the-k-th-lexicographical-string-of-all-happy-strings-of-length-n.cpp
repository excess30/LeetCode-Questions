class Solution {
public:
    
    void rec(int n, int k,vector<char>&c, string curr,vector<string>& ans)
    {
        if(ans.size()==k)
        {
            return;
        }
        if(curr.size()==n)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<c.size();i++)
        {
            if(curr.back()!=c[i]||curr.size()==0)
            {
                rec(n,k,c,curr+c[i],ans);
            }
        }
    }
    
    string getHappyString(int n, int k) 
    {
        vector<char>c = {'a','b','c'};
        vector<string>ans;
        rec(n,k,c,"",ans);
        if(ans.size()>=k)
        {
            return ans[k-1];
        }
        return "";
    }
};