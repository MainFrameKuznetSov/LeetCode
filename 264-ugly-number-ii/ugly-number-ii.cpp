class Solution {
public:
    int nthUglyNumber(int n) {
        int fact[]={2,3,5};
        priority_queue<long long,vector<long long>,greater<long long>>heap;
        unordered_set<long long>vis;
        heap.push(1);
        vis.insert(1);
        long long ans;
        for(int i=0;i<n;++i)
        {
            ans=heap.top();
            heap.pop();
            for(int i:fact)
            {
                long long temp=ans*i;
                if(vis.find(temp)==vis.end())
                {
                    heap.push(temp);
                    vis.insert(temp);
                }
            }
        }
        return ans;
    }
};