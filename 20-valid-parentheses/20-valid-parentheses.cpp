class Solution {
public:
    bool isValid(string s) 
    {
        int n = s.size();
        stack<char>st;
        for(auto x:s)
        {
            if(st.empty())
            {
                st.push(x);
            }
            else if(st.top()=='(' && x==')')
            {
                st.pop();
            }
            else if(st.top()=='{' && x=='}')
            {
                st.pop();
            }
            else if(st.top()=='[' && x==']')
            {
                st.pop();
            }
            else
            {
                st.push(x);
            }
        }
        if(st.empty()==true)
        {
            return true;
        }
        return false;
    }
};