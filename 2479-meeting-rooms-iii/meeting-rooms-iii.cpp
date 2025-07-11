class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m=meetings.size();
        vector<int>vec(n,0);
        vector<long long>time(n,0);
        sort(meetings.begin(),meetings.end());

        for(int i=0;i<m;++i)
        {
            int l=meetings[i][0],r=meetings[i][1];
            bool f=0;
            int mn=-1;
            long long val=1e18;
            for(int j=0;j<n;++j)
            {
                if(time[j]<val)
                {
                    val=time[j];
                    mn=j;
                }
                if(time[j]<=l)
                {
                    f=1;
                    ++vec[j];
                    time[j]=r;
                    break;
                }
            }
            if(!f)
            {
                ++vec[mn];
                time[mn]+=(1LL*(r-l));
            }
        }

        int mx=-1,ans=-1;
        for(int i=0;i<n;++i)
        {
            if(vec[i]>mx)
            {
                mx=vec[i];
                ans=i;
            }
        }
        return ans;
    }
};