class Solution {
public:
    int longestPalindromeSubseq(string s) {
         string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s1.size();
        int m = s2.size();
        int dp[n+1][m+1];
        
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};