#define ll long long
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int>lightCount(n,0);
        for(int i=0;i<n;++i)
        {
            string val=bank[i];
            int cnt=0;
            for(char ch:val)
            {
                if(ch=='1')
                    ++cnt;
            }
            lightCount[i]=cnt;
        }
        ll ans=0;
        int pre=0;
        for(int i=1;i<n;++i)
        {
            if(lightCount[i]==0)
                continue;
            ans+=(ll)lightCount[i]*lightCount[pre];
            pre=i;
            //cout<<i<<" "<<ans<<"\n";
        }
        return (int)ans;
    }
};