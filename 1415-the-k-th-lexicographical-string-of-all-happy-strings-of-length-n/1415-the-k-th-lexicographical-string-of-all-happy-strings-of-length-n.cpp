class Solution {
public:
    
    void findString(vector<string>& res,vector<char>& chars, string temp, int n, int k)
    {
        if(res.size()==k)
        {
            return;
        }
        if(temp.size()==n)
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<chars.size();i++)
        {
            if(temp.back()!=chars[i]||temp.size()==0)
            {
                findString(res,chars,temp+chars[i],n,k);
            }
        }
    }
    
    string getHappyString(int n, int k)
    {
        vector<string>res;
        vector<char>chars={'a','b','c'};
        findString(res,chars,"",n,k);
        if(res.size()>=k)
        {
            return res[k-1];
        }
        return "";
    }
};