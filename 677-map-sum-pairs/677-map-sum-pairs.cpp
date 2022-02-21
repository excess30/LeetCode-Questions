class MapSum {
public:
    unordered_map<string,int>mp;
    MapSum() {
        
    }
    
    void insert(string key, int val)
    {
        mp[key]=val;    
    }
    
    int sum(string prefix)
    {
        int cnt=0;
        string s,subs;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            s=i->first;
            if(prefix.size()>s.size())
            {
                continue;
            }
            subs=s.substr(0,prefix.size());
            if(subs==prefix)
            {
                cnt+=i->second;
            }
        }
        return cnt;
    }
};


