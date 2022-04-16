class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) 
    {
        vector<int>ans;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            j=i;
            int row = startPos[0];
            int col = startPos[1];
            while(j<s.size())
            {
                if(s[j]=='U')
                {
                    row--;
                }
                else if(s[j]=='D')
                {
                    row++;
                }
                else if(s[j]=='L')
                {
                    col--;
                }
                else
                {
                    col++;
                }
                if(row<0||row>=n||col<0||col>=n)
                {
                    break;
                }
                j++;
            }
            ans.push_back(j-i);
        }
        return ans;
    }
};

