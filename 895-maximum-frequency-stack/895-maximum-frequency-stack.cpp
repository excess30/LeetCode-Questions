//Source: Ayushi Sharma
//Create a max heap to store elements with respect to frequency. STructure will be. {freq[val],{pos,val}} where pos will be the tie breaker if 2 elements have same frequency.

class FreqStack {
public:
    
    priority_queue<pair<int,pair<int,int>>>pq;
    unordered_map<int,int>freq;
    int pos=0;
    
    FreqStack() {
        
    }
    
    void push(int val) 
    {
        pq.push({freq[val],{pos,val}});    
        freq[val]++;
        pos++;
    }
    
    int pop() 
    {
        auto y = pq.top();
        pq.pop();
        auto x = y.second.second;
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */