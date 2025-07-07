class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(events.begin(),events.end());
        int ptr=0,ans=0,n=events.size();
        for(int i=1;i<=100000;++i)
        {
            while(!pq.empty() && pq.top()<i)
                pq.pop();
            while(ptr<n && events[ptr][0]<=i)
            {
                pq.push(events[ptr][1]);
                ++ptr;
            }
            if(!pq.empty())
            {
                pq.pop();
                ++ans;
            }
        }
        return ans;
    }
};