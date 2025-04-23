class Solution {
public:
    int countLargestGroup(int n) {
        vector<int>cnt(37,0);
        int mx=1,ans=1;
        cnt[1]=1;
        for(int i=2;i<=n;++i)
        {
            int sum=0;
            for(int j=i;j>0;j/=10)
                sum+=j%10;
            int temp=++cnt[sum];
            if(temp==mx)
                ++ans;
            else if(temp>mx)
            {
                mx=temp;
                ans=1;
            }
        }
        return ans;
    }
};