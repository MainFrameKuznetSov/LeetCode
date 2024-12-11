class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int>frq(100001,0);
        int mx=0,mn=INT_MAX,cnt=0,mcnt=0;
        for(int i:nums)
        {
            ++frq[i];
            mx=max(mx,i);
            mn=min(mn,i);
        }
        for(int l=mn,r=mn;r<=mx;++r)
        {
            cnt+=frq[r];
            while((r-l)>k*2)
            {
                cnt-=frq[l];
                ++l;
            }
            mcnt=max(mcnt,cnt);
        }
        return mcnt;
    }
};