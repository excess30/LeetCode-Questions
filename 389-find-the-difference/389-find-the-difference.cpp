class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map<char,int>mp;
        for(auto x:s)
        {
            mp[x]++;
        }
        for(auto y:t)
        {
            if(mp[y]--<=0)
            {
                return y;
            }
        }
        return '/0';
    }
};