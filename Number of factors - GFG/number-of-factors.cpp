// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int countFactors(int N){
        //code here
        int cnt=0;
        for(int i=1;i<=N;i++)
        {
            if(N%i==0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.countFactors(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends