class Solution {
public:
  int getFrequency(string &s){
        
        int cache[26];
        memset(cache,0,sizeof(cache));
        
        char smallest = s[0];
        for(char ch : s){
            cache[ch -'a']++;
            if(smallest > ch)
                smallest = ch;
        }
        return cache[smallest -'a'];
        
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        unordered_map<string, int> smallestFreq;
        vector<int> result;
        for(string &word : words){
            smallestFreq[word] = getFrequency(word);
        }
        
        for(string &query : queries){
            int freq = getFrequency(query);
            int count = 0;
            for(string &word : words){
                if(freq < smallestFreq[word])
                    count++;
            }
            result.push_back(count);
        }
        return result;
        
    }
};


 