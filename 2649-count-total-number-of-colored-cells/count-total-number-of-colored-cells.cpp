class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0,lim=(n*2)-1;
        for(int i=1;i<=lim;i+=2)
        {
            if(i!=lim)
                ans+=(i*2);
            else
                ans+=i;
        }
        return ans;
    }
};