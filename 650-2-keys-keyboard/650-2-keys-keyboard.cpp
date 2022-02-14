class Solution {
public:
    int minSteps(int n)
    {
        if(n<=5)
        {
            return n==1?0:n;
        }
        vector<int>primes={2,3,5,7,11,13,17,19,23,29,31};
        for(auto x:primes)
        {
            if(n%x==0)
            {
                return x+minSteps(n/x);
            }
        }
        return n;
    }
};

