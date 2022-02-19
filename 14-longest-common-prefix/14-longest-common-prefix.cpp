class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size()==0)
        {
            return "";
        }
        if(strs.size()==1)
        {
            return strs[0];
        }
        string prefix = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            if(strs[i].size()<prefix.size())
            {
                prefix=strs[i];
            }
        }
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[0].size();j++)
            {
                if(prefix[j]!=strs[i][j])
                {
                    prefix=prefix.substr(0,j);
                    break;
                }
            }
        }
        return prefix;
    }
};
