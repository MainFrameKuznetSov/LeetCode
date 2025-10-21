class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int opt) {
        int lim=0;
        for(int i=0;i<nums.size();++i)
            lim=max(lim,nums[i]);
        int sz=lim+k;
        sz+=2;
        vector<int>frq(sz,0);
        for(int it:nums)
            ++frq[it];
        vector<int>pre(sz,0);
        pre[0]=frq[0];
        for(int i=1;i<sz;++i)
            pre[i]=pre[i-1]+frq[i];
        int ans=0;
        for(int i=0;i<sz;++i) 
        {
            if(frq[i]==0 && opt==0)
                continue;
            int l=max(0,i-k),r=min(sz-1,i+k);
            int full=pre[r];
            if(l>0)
                full-=pre[l-1];
            int extra=full-frq[i];
            ans=max(ans,frq[i]+min(opt,extra));
        }
        return ans;
    }
};