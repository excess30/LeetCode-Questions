class Twitter {
public:
    
    unordered_map<int,set<int>>mp;
    set<pair<int,pair<int,int>>>tweets;
    int t=0;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        tweets.insert({t,{tweetId,userId}});
        t++;
    }
    
    vector<int> getNewsFeed(int userId)
    {
        mp[userId].insert(userId);
        vector<int>ans;
        int cnt=10;
        for(auto it=tweets.rbegin();it!=tweets.rend();it++)
        {
            if(mp[userId].count(it->second.second) && cnt>0)
            {
                ans.push_back(it->second.first);
                cnt--;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) 
    {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        mp[followerId].erase(followeeId);    
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */