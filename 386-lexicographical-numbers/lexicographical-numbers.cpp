class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans(n);
        int val=1;
        for(int i=0;i<n;++i)
        {
            ans[i]=val;
            if(n<val*10)
            {
                if(val==n)
                    val/=10;
                ++val;
                while(val%10==0)
                    val/=10;
            }
            else
                val*=10;
        }
        return ans;
    }
};