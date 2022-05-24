//My approach : 64/231 passed
//Push -1 into the stack first and then push the indices of the values which have '(' in them and once yoy encounter a ')' then pop the element from the stack.If popping that element results in the stack being empty push that index in the stack or else find the max length by using i-stk.top().


class Solution {
public:
     int longestValidParentheses(string s) 
    {
        stack<int> stk;
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++)
        {
            int t=stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
    }
};



