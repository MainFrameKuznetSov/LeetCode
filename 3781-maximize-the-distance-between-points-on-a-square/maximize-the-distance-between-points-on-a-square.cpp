#define ll long long

class Solution {
public:

    vector<ll>vec;

    ll edit(int a,int b,int side)
    {
        if(a==0)
            return b;
        if(b==side)
            return a+side;
        if(a==side)
            return 1LL*3*side-b;
        return 1LL*4*side-a;
    }

    bool helper(ll mid,ll k,ll peri)
    {
        int hf=vec.size()/2;
        for(int i=0;i<hf;++i)
        {
            ll data=vec[i],pre=data,ind=-1,cnt=k-1;
            while(cnt>0)
            {
                ll tar=pre+mid;
                auto it=lower_bound(vec.begin()+ind+1,vec.end(),tar);
                if(it==vec.end() || *it+mid>peri+data)
                    break;
                pre=*it;
                ind=it-vec.begin();
                --cnt;
            }
            if(cnt==0)
                return true;
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n=points.size();
        ll peri=1LL*4*side;
        for(auto it:points)
            vec.push_back(edit(it[0],it[1],side));
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;++i)
            vec.push_back(peri+vec[i]);
        ll lo=0,hi=peri/k;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            if(helper(mid,k,peri))
                lo=mid+1;
            else
                hi=mid-1;
        }
        return hi;
    }
};