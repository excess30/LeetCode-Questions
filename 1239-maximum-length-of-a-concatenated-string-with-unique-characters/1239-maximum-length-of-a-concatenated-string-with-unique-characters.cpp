class Solution {
public:
    int len=0;
    
    bool isUnique(string &str)
    {
        unordered_set<char>s;
        for(int i=0;i<str.size();i++)
        {
            if(s.find(str[i])!=s.end())
            {
                return false;
            }
            s.insert(str[i]);
        }
        return true;
    }
    
    void backtrack(string curr, int idx, vector<string>& arr)
    {
        if(!isUnique(curr))
        {
            return;
        }
        if(curr.size()>len)
        {
            len=curr.size();
        }
        for(int i=idx;i<arr.size();i++)
        {
            backtrack(curr+arr[i],i+1,arr);
        }
    }
    
    int maxLength(vector<string>& arr) 
    {
        backtrack("",0,arr);
        return len;
    }
};