/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums.size()==1 && nums[mid]==target)
            {
                return {0,0};
            }
            if(nums[mid]==target && nums[mid-1]==target)
            {
                return {mid-1,mid};
            }
            if(nums[mid]==target && nums[mid+1]==target)
            {
                return {mid,mid+1};
            }
            if(nums[mid]>target)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        pair<vector<int>::iterator,vector<int>::iterator> range;
        range = equal_range(nums.begin(), nums.end(), target);
        int Tleft = distance(nums.begin(), range.first);
        if (Tleft == nums.size() || nums[Tleft] != target) return {-1, -1};
        return {Tleft, (int)distance(nums.begin(), range.second) - 1};
    }
};