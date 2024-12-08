class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size(),ans=0;
        sort(events.begin(),events.end(),[&](vector<int>a,vector<int>b)
        {
            return b[0]>a[0];
        });
        vector<int>suff(n);
        suff[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;--i)
            suff[i]=max(events[i][2],suff[i+1]);
        
        for(int i=0;i<n;++i)
        {
            int l=i+1,r=n-1,nxt=-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(events[mid][0]>events[i][1])
                {
                    nxt=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            if(nxt!=-1)
                ans=max(ans,events[i][2]+suff[nxt]);
            ans=max(ans,events[i][2]);
        }
        return ans;
    }
};