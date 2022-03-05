class Solution {
public:
    
    void generate(int l, int r,vector<string>& res, string temp)
    {
        if(l==0 && r==0)
        {
            res.push_back(temp);
            return;
        }
        if(l>0)
        {
            generate(l-1,r,res,temp+"(");
        }
        if(r>l)
        {
            generate(l,r-1,res,temp+")");
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>res;
        generate(n,n,res,"");
        return res;
    }
};

