class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
         if(position.empty()||speed.empty())
         {
            return 0;
         }
         vector<pair<int,double>>interval;
        for(int i=0;i<position.size();i++)
        {
            interval.push_back(make_pair(position[i], (double)(target - position[i])/(double)(speed[i])));
        }
        sort(interval.begin(),interval.end());
        auto p = interval[interval.size()-1];
        int fleet=0;
        for(int i=interval.size()-2;i>=0;i--)
        {
            if(interval[i].second>p.second)
            {
                fleet++;
                p=interval[i];
            }
        }
        return fleet+1;
    }
};


