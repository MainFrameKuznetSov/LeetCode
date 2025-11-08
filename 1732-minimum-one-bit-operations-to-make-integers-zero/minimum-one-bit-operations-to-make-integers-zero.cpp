class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans=0,k=0,msk=1;
        while(msk<=n) 
        {
            if((n&msk)!=0)
                ans=(1<<(k+1))-1-ans;            
            msk<<=1;
            ++k;
        }
        return ans;
    }
};