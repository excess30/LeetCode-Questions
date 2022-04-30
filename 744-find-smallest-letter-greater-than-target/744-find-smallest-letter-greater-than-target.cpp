/*class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int n = letters.size();
        int l=0,h=n-1,x=0;
        while(l<h)
        {
            int mid = l+(h-l)/2;
            if(letters[mid]>target)
            {
                h=mid;
            }
            else
            {
                x=l;
                l=mid+1;
            }
        }
        return letters[x];
    }
};
*/


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;

    }
};