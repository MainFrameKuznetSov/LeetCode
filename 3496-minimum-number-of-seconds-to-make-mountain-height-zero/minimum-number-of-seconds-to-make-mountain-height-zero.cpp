#define ll long long

class Solution {
public:

    bool helper(ll mid,int mountainHeight,vector<int>&workerTimes)
    {
        ll sum=0;
        for(ll i:workerTimes)
        {
            ll cnt=(mid*2)/i,temp=(ll)((sqrtl(cnt*4+1)-1)/2);
            sum+=temp;
            if(sum>=mountainHeight)
                return true;
        }
        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll lo=0,hi=(ll)1e18;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            if(helper(mid,mountainHeight,workerTimes))
                hi=mid-1;
            else
                lo=mid+1;
        }
        return lo;
    }
};