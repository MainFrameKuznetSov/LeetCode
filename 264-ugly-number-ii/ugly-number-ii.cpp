class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ans;
        ans.push_back(1);
        int m2=0,m3=0,m5=0;
        for(int i=1;i<n;++i)
        {
            int temp=min(ans[m2]*2,min(ans[m3]*3,ans[m5]*5));
            ans.push_back(temp);
            if(temp==ans[m2]*2)
                ++m2;
            if(temp==ans[m3]*3)
                ++m3;
            if(temp==ans[m5]*5)
                ++m5;
        }
        return ans[n-1];
    }
};