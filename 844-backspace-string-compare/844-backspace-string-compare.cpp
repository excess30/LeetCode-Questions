class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        stack<char>stt;
        stack<char>st;
        for(auto x:s)
        {
            if(x!='#')
            {
                stt.push(x);
            }
            else if(stt.empty()==false && x=='#')
            {
                stt.pop();
            }
        }
        for(auto x:t)
        {
            if(x!='#')
            {
                st.push(x);
            }
            else if(st.empty()==false && x=='#')
            {
                st.pop();
            }
        }
        string ans="";
        string ans1="";
        while(stt.empty()==false)
        {
            ans+=stt.top();
            stt.pop();
        }
        while(st.empty()==false)
        {
            ans1+=st.top();
            st.pop();
        }
        if(ans==ans1)
        {
            return true;
        }
        return false;
    }
};