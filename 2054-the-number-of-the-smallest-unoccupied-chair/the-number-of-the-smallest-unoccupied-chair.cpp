class Solution {
public:
    int smallestChair(vector<vector<int>>& time, int target) {
        int n=time.size(),ans=-1;
        vector<pair<int,int>>pr;
        for(int i=0;i<n;++i)
            pr.push_back({time[i][0],i});
        sort(pr.begin(),pr.end());
        priority_queue<int,vector<int>,greater<int>>chair;
        for(int i=0;i<n;++i)
            chair.push(i);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto iter:pr)
        {
            int start=iter.first;
            int ind=iter.second;
            while(!pq.empty() && pq.top().first<=start)
            {
                chair.push(pq.top().second);
                pq.pop();
            }
            int temp=chair.top();
            chair.pop();
            if(ind==target)
                return temp;
            pq.push({time[ind][1],temp});
        }
        return -1;
    }
};