class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
         set<string> ans;
        for(string email : emails)
        {
            string temp = "";
            int i;
            for(i=0; email[i] != '@'; i++)
            {
                if(email[i] == '.')
                    continue;
                else if(email[i] == '+')
                    break;
                else
                    temp += email[i];
            }
            i = email.find('@');
            temp += email.substr(i, email.length()-i);
            ans.insert(temp);
        }
        return ans.size();
    }
};

   