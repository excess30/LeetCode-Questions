class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        vector<int> countA(7), countB(7), countSame(7);
        int n = tops.size();
        for (int i = 0; i < n; i++) {
            int a = tops[i], b = bottoms[i];
            countA[a] += 1;
            countB[b] += 1;
            if (a == b) countSame[a] += 1;
        }
        int ans = n;
        for (int v = 1; v <= 6; v++) {
            if (countA[v] + countB[v] - countSame[v] == n) {
                int minSwap = min(countA[v], countB[v]) - countSame[v];
                ans = min(ans, minSwap);
            }
        }   
        return ans == n ? -1 : ans;
    }
};