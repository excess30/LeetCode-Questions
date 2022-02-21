class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
    int arr[128] = {0};
      int result = 0, i = 0, cnt = 0;
      for (int j = 0; j < s.size(); ++j) {
          arr[s[j]]++;
          if (arr[s[j]] == 1) {
              cnt++;
              result = max(result, cnt);
          } else {
              while (i < j and arr[s[j]] > 1) {
                  arr[s[i]]--;
                  i++;
              }
              cnt = j - i + 1;
              result = max(result, cnt);
          }
      }
      return result;
    }
};

