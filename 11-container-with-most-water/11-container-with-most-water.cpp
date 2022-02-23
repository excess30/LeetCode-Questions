class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int i=0,j=n-1;
        int area=0,res=0;
        while(i<j)
        {
            if(height[i]<=height[j])
            {
                area=height[i]*(j-i);
                i++;
            }
            else
            {
                area=height[j]*(j-i);
                j--;
            }
            res=max(res,area);
        }
        return res;
    }
};

