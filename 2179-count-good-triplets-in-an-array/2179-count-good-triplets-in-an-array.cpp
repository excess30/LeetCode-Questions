/*Idea :-
We iterate on every element of first array and find its occurance in the second array lets say that is j. now our answer contribute by this element would be :-
Number of overlapping elements in n1 from 0 to i and in n2 from 0 to j. lets say this is pref[i]
and multiply this with number of overlapping elements in n1 from i + 1 to n and in n2 from j + 1 to n lets say this suff[i]

now answer is simply multiplication of these two.*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n); 
        
        for(int i = 0; i < n; i++){
            pos[nums2[i]] = i;
        }
        vector<int> pref(n) , suff(n);
        ordered_set s,s2;
        for(int i = 0; i < n; i++){
            pref[i] = s.order_of_key(pos[nums1[i]]);
            s.insert(pos[nums1[i]]);
        }
       
        for(int i = n-1; i >= 0; i--){
            suff[i] = s2.order_of_key(-pos[nums1[i]]);
            s2.insert(-pos[nums1[i]]);
        }
        long long ans = 0;
        for(int i = 1; i < n-1; i++){
            ans = ans + pref[i]*1LL*suff[i];
        }
        return ans;
    }
};

/*The reason why I used pbds instead of set or other similar container, because calling lower_bound many times give TLE. That's why use pbds for calculating number of elements strictly smaller or larger than my current number.

How to get number of elements strictly greater ?
Well, there is a trick insert all elements as -ve now call order of key for negative it will automatically give number of elements greater than my current number.*/