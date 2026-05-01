#define ll long long

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        ll tot=0,temp=0;
        for(int i=0;i<n;++i)
        {
            tot+=nums[i];
            temp+=1LL*i*nums[i];
        }
        ll ans=temp;
        for(int i=1;i<n;++i)
        {
            temp=temp+tot-(1LL*n*nums[n-i]);
            ans=max(ans,temp);
        }
        return ans;
    }
};