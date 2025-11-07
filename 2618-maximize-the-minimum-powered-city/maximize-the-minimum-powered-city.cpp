#define ll long long

class Solution {
public:

    bool helper(vector<ll>pre,vector<int>&stations,ll mid,int r,int k)
    {
        int n=stations.size();
        vector<ll>add(n,0);
        ll done=0,temp=0;
        for(int i=0;i<=r && i<n;++i)
            temp+=stations[i];
        for(int i=0;i<n;++i)
        {
            if(i-r>=1)
                temp-=stations[i-r-1]+add[i-r-1];
            
            if(temp<mid)
            {
                ll rem=mid-temp;
                done+=rem;
                if(done>k)
                    return 0;
                int ptr=min(n-1,i+r);
                add[ptr]+=rem;
                temp+=rem;
            }

            if(i+r+1<n)
                temp+=stations[i+r+1];
        }
        return 1;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<ll>pre(n+1,0);
        pre[0]=0;
        for(int i=1;i<n;++i)
            pre[i+1]=pre[i]+stations[i];
        ll sum=0;
        for(int i:stations)
            sum+=(ll)i;
        ll left=0,right=sum+k;
        while(left<=right)
        {
            ll mid=left+(right-left)/2;
            if(helper(pre,stations,mid,r,k))
                left=mid+1;
            else
                right=mid-1;
        }
        return right;
    }
};