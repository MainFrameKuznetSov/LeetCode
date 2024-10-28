const int N=1e5;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size(),m=0,ans=0;
        bitset<N+1>hX=0;
        for(int i:nums)
        {
            hX[i]=1;
            m=max(m,i);
        }
        for(long long it:nums)
        {
            int curr=1;
            for(long long i=it*it;i<=m;i*=i)
            {
                if(hX[i])
                    ++curr;
                else
                    break;
            }
            ans=max(ans,curr);
            if(ans==5)
                break;
        }
        return ans<2?-1:ans;
    }
};