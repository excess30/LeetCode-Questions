class Solution {
public:
    int titleToNumber(string columnTitle) 
    {
        int n = columnTitle.size();
        int colNo=0;
        long long p=1;
        for(int i = n-1;i>=0;i--)
        {
            colNo += (p*(columnTitle[i]-64));
            p*=26;
        }
        return colNo;
    }
};