#define ll long long

class Solution {
public:

    ll helper(ll mid,vector<int>&bloomDay,int k)
    {
        ll cnt=0,bqt=0;
        for(ll i:bloomDay)
        {
            if(i<=mid)
                ++cnt;
            else
            {
                bqt+=(cnt/k);
                cnt=0;
            }
        }
        bqt+=(cnt/k);
        return bqt;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        //sort(bloomDay.begin(),bloomDay.end());
        int n=bloomDay.size();
        ll right=INT_MAX,left=INT_MIN,ans=-1;
        for(ll i:bloomDay)
        {
            left=min(left,i);
            right=max(right,i);
        }
        //left=bloomDay[0],right=bloomDay[n-1];
        //cout<<left<<" "<<right<<"\n";
        while(left<=right)
        {
            ll mid=left+(right-left)/2;
            if(helper(mid,bloomDay,k)>=m)
            {
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return (int)ans;
    }
};