class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size(),ans=INT_MIN;
        for(int i=n-k;i<n;++i)
        {
            int temp=0;
            for(int j=i;j>=0;j-=k)
            {
                temp+=energy[j];
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};