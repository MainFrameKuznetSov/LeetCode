#define lim 200
#define INF (int)1e9

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size(),size=(n+lim-1)/lim,ans=0;
        vector<int>blockLevelAdd(size,0),accum(n,0);
        vector<vector<int>>blockLeft(size,vector<int>(n*2+1,INF));
        unordered_map<int,int>last;

        for(int r=0;r<n;++r) 
        {
            int l=last.count(nums[r])?last[nums[r]]+1:0,delta=nums[r]%2?-1:+1;
            int lblk=l/lim,rblk=r/lim;
            for(int blk=lblk;blk<=rblk;++blk) 
            {
                if(blk==lblk || blk==rblk) 
                {
                    for(int i=min(blk*lim+lim-1,n-1);i>=blk*lim;--i)
                        blockLeft[blk][accum[i]+n]=INF;
                    for(int i=min(blk*lim+lim-1,n-1);i>=blk*lim;--i) 
                    {
                        accum[i]+=(i>=l && i<=r)?delta:0;
                        blockLeft[blk][accum[i]+n]=i;
                    }
                }
                else 
                    blockLevelAdd[blk]+=delta;
            }
            for(int blk=0;blk<=rblk;++blk)
                ans=max(ans,r-blockLeft[blk][n-blockLevelAdd[blk]]+1);
            last[nums[r]]=r;
        }
        return ans;
    }
};