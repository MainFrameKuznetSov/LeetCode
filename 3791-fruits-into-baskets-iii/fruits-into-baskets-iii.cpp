class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size(),lim=1;
        while(lim<=n) 
            lim <<= 1;

        vector<int> vec(lim << 1);
        for(int i=0;i<n;++i)
            vec[lim+i]=baskets[i];
        
        for(int i=lim-1;i>0;--i)
            vec[i]=max(vec[2*i],vec[2*i+1]);

        int count=0;
        for(int it:fruits) 
        {
            int ind=1;
            if(vec[ind]<it) 
            {
                count++;
                continue;
            }

            while(ind<lim) 
            {
                if(vec[2*ind]>=it)
                    ind=2*ind;
                else
                    ind=2*ind+1;
            }

            vec[ind]=-1;
            while(ind>1) 
            {
                ind>>=1;
                vec[ind]=max(vec[2*ind],vec[2*ind+1]);
            }
        }
        return count;
    }
};