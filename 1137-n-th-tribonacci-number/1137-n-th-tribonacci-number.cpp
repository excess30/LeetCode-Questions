class Solution {
public:
    int tribonacci(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1||n==2)
        {
            return 1;
        }
        if(n==3)
        {
            return 2;
        }
        int t[n+1];
        t[0]=0;
        t[1]=1;
        t[2]=1;
        t[3]=2;
        for(int i=4;i<=n;i++)
        {
            t[i]=t[i-1]+t[i-2]+t[i-3];
        }
        return t[n];
    }
};