class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(auto x:s)
        {
            mp[x]++;
        }
        for(auto y:mp)
        {
            pq.push({y.second,y.first});
        }
        string ans="";
        while(pq.empty()==false)
        {
            auto ch = pq.top().second;
            auto i = pq.top().first;
            while(i--)
            {
                ans+=ch;
            }
            pq.pop();
        }
        return ans;
    }
};