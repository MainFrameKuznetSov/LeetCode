#define ll long long
class Solution {
public:

    ll helper(ll mid,vector<int>&bloomDay,int k)
    {
        int ans=0,cnt=0;
        for(ll i:bloomDay)
        {
            if(mid>=i)
                ++cnt;
            else
            {
                ans+=(cnt/k);
                cnt=0;
            }
        }
        return ans+(cnt/k);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ll n=bloomDay.size();
        if(n<(k*1LL*m))
            return -1;
        ll left=1,right=0;
        for(ll i:bloomDay)
            right=max(i,right);
        while(left<=right)
        {
            ll mid=left+(right-left)/2;
            if(helper(mid,bloomDay,k)>=m)
                right=mid-1;
            else
                left=mid+1;
        }
        return left;
    }
};