class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int f=0;
        unordered_map<int,int>m;
        for(auto u:nums1)
            for(auto v:nums2)
                m[u+v]++;

        for(auto u:nums3)
            for(auto v:nums4)
            {
                auto it=m.find(0-u-v);
                if(it!=m.end())
                    f += it->second;
            }

        return f;

    }
};