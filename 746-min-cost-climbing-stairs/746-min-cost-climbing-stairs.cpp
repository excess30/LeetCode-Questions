class Solution {
public:
    
    int t[1001];
    int minCost(vector<int>& cost, int n)
    {
        if(n<0)
        {
            return 0;
        }
        if(t[n]!=0)
        {
            return t[n];
        }
        if(n==0||n==1)
        {
            return cost[n];
        }
        t[n]=cost[n]+min(minCost(cost,n-1),minCost(cost,n-2));
        return t[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        memset(t,0,sizeof(t));
        return min(minCost(cost,n-1),minCost(cost,n-2));
    }
};

