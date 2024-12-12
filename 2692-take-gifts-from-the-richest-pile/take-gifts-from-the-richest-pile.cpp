class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int,vector<int>>pq;
        int n=gifts.size();
        for(int i=0;i<n;++i)
            pq.push(gifts[i]);
        while(k--)
        {
            int curr=pq.top();
            pq.pop();
            pq.push(floor(sqrt(curr)));
        }
        long long sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};