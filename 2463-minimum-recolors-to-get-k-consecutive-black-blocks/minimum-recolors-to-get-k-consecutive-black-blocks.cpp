class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ind=0,W=0,ans=INT_MAX;
        for(int i=0;i<blocks.size();++i)
        {
            if(blocks[i]=='W')
                ++W;
            if(i-ind+1==k)
            {
                ans=min(ans,W);
                if(blocks[ind]=='W')
                    --W;
                ++ind;
            }
        }
        return ans;
    }
};