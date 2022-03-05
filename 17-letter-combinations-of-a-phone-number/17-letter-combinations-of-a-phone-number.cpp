class Solution {
public:
    
    void findCombinations(vector<string>& res, string temp, string digits,vector<string>& dict,int idx)
    {
        if(idx==digits.size())
        {
            res.push_back(temp);
            return;
        }
        for(auto x:dict[digits[idx]-'2'])
        {
            findCombinations(res,temp+x,digits,dict,idx+1);
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size()==0)
        {
            return {};
        }
        vector<string>res;
        vector<string>dict = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        findCombinations(res,"",digits,dict,0);
        return res;
    }
};