class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin(),strs.end());
        string prefix = strs[0];
        for(int i=0;i<strs.size();i++)
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
