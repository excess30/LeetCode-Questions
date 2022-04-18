class Solution {
public:
    long long minimumRemoval(vector<int>& beans) 
    {
        int n= beans.size();
        sort(beans.begin(),beans.end());
        long long int max_area=INT_MIN,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=beans[i];
            max_area = max(max_area,beans[i]*1LL*(n-i));
        }
        return sum-max_area;
    }
};