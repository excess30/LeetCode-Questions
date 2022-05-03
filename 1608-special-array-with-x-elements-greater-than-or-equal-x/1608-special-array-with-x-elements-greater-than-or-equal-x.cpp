/*class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        int n = nums.size();
        set<int>s;
        for(auto x:nums)
        {
            s.insert(x);
        }
        sort(nums.begin(),nums.end());
        int l=1,h=nums[n];
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(((n-mid)+1>=nums[mid]) && (s.find(nums[mid])!=s.end()))
            {
                return nums[mid];
            }
            else if(((n-mid)+1>=nums[mid]) && (s.find(nums[mid])==s.end()))
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
       return -1; 
    }
};    */
class Solution {
public:
int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // O(NlogN)
    const int N = nums.size();
    if (nums[0] >= N) return N;
    int l = 1, r = N - 1;
    while (l <= r) { // O(LogN) * O(1)
        int m = l + (r - l) / 2;
        if (nums[m] >= (N - m) && nums[m - 1] < (N - m)) return (N - m);
        else if (nums[m] >= (N - m)) r = m - 1;
        else l = m + 1;
    }
    return -1;
    }
};