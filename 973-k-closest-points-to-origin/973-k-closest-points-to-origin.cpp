class Solution {
private:
    struct compare
    {
        bool operator()(vector<int>& p, vector<int>& q)
        {
            return p[0]*p[0] + p[1]*p[1] > q[0]*q[0] + q[1]*q[1];
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(auto x:points)
        {
            pq.push(x);
        }
        vector<vector<int>>res;
       for(int i=0;i<k;i++)
       {
           res.push_back(pq.top());
           pq.pop();
       }
        return res;
    }
};
