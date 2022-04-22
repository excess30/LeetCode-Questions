class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int lenOfS=s.size();
        int lenOfP=p.size();
        vector<int>pFreq(26,0);
        vector<int>sFreq(26,0);
        if(lenOfS<lenOfP)
        {
            return {};
        }
        vector<int>ans;
        for(int i=0;i<lenOfP;i++)
        {
            pFreq[p[i]-'a']++;
            sFreq[s[i]-'a']++;
        }
        if(pFreq==sFreq)
        {
            ans.push_back(0);
        }
        for(int i=lenOfP;i<lenOfS;i++)
        {
            sFreq[s[i-lenOfP]-'a']--;
            sFreq[s[i]-'a']++;
            if(pFreq==sFreq)
            {
                ans.push_back(i-lenOfP+1);
            }
        }
        return ans;
    }
};