class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int n = strs.size();
        string prefix = strs[0];
        for(int i=0;i<n;i++)
        {
            if(strs[i].size()<prefix.size())
            {
                prefix=strs[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<strs[i].size();j++)
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