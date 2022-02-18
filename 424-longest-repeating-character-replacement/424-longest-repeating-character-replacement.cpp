class Solution {
public:
    int characterReplacement(string s, int k) 
    {
         vector<int> m(128, 0);
        int count = 0, begin = 0, end = 0, d = 0;
        while(end < s.size())
        {
            m[s[end]]++;
            if (m[s[end]] > count) count = m[s[end]];
            end++;
            if (end - begin - count > k)
            {
                m[s[begin]]--;
                begin++;
            }
        }
        d = end - begin;
        return d;
    }
};

