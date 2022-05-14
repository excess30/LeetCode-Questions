class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = s.size();
        if(wordDict.size()==0)
        {
            return false;
        }
        bool t[n+1];
        memset(t,false,sizeof(t));
        t[0]=true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(t[j])
                {
                    string c = s.substr(j,i-j);
                    auto d = find(wordDict.begin(),wordDict.end(),c);
                    if(d!=wordDict.end())
                    {
                        t[i]=true;
                        break;
                    }
                }
            }
        }
        return t[n];
    }
};
