#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=(n)-1;i>=0;--i)
#define lloop(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
#define vpii vector<pair<int,int>>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define F first
#define S second
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>aux1(n),aux2(n);
        set<pair<int,int>>st;
        rep(i,n)
        {
            while(!st.empty() && prev(st.end())->F>=nums[i])
                st.erase(prev(st.end()));
            aux1[i]=st.empty()?-1:prev(st.end())->S;
            st.insert({nums[i],i});
        }
        
        st.clear();
        
        rrep(i,n)
        {
            while(!st.empty() && prev(st.end())->F>=nums[i])
                st.erase(prev(st.end()));
            aux2[i]=st.empty()?n:prev(st.end())->S;
            st.insert({nums[i],i});
        }

        st.clear();
        
        vpii pr;
        rep(i,n)
        {
            if(nums[i])
                pr.pb({nums[i],i});
        }
        int sz=pr.size();
        sort(all(pr));
        int ans=0;
        for(int i=0;i<sz;)
        {
            int ptr=i+1,cnt=1;
            while(ptr<sz && pr[ptr].F==pr[i].F)
                ++ptr;
            lloop(k,i+1,ptr-1)
            {
                int pre=pr[k-1].S,cur=pr[k].S;
                if(aux2[pre]<=cur)
                    ++cnt;
            }
            ans+=cnt;
            i=ptr;
        }
        return ans;
    }
};