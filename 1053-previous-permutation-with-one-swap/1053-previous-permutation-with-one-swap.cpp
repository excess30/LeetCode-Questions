class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) 
    {
         int i;
        for(i=arr.size()-2;i>=0;i--)
        {
            if(arr[i+1]<arr[i])
            {
                break;
            }
        }
        if(i<0)
            return arr;
        for(int j=arr.size()-1;j>=i+1;j--)
        {
            if(arr[j]<arr[i] && arr[j]!=arr[j-1])
            {
                swap(arr[j],arr[i]);
                break;
            }
        }
        return arr;
    }
};