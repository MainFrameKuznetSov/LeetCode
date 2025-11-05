#define ll long long

ll ans;
set<pair<int,int>>st1;
set<pair<int,int>>st2;
map<int,int>mp;

void put(pair<int,int>p,int x) 
{
    if(st2.size()<x || *(st2.begin())<p) 
    {
        ans+=p.first*1LL*p.second;
        st2.insert(p);
        if(st2.size()>x) 
        {
            auto it=*st2.begin();
            ans-=it.first*1LL*it.second;
            st2.erase(it);
            st1.insert(it);
        }
    } 
    else
        st1.insert(p);
}

void rub(pair<int,int>p) 
{

    if(p>=*(st2.begin())) 
    {
        ans-=p.first*1LL*p.second;
        st2.erase(p);
        if(st1.size()>0) 
        {
            auto it=*st1.rbegin();
            ans+=it.first*1LL*it.second;
            st1.erase(it);
            st2.insert(it);
        }
    } 
    else
        st1.erase(p);
}

void insert(int num, int x) 
{
    if(mp[num])
        rub({mp[num],num});
    ++mp[num];
    put({mp[num],num},x);
}

void remove(int num, int x) 
{
    rub({mp[num],num});
    --mp[num];
    if(mp[num])
        put({mp[num],num},x);
}

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        ans=0;
        st1.clear();
        st2.clear();
        mp.clear();
        vector<ll>res;
        for(int i=0;i<nums.size();++i) 
        {
            insert(nums[i],x);
            if(i>=k)
                remove(nums[i-k],x);
            if(i>=k-1)
                res.push_back(ans);
        }
        return res;
    }
};