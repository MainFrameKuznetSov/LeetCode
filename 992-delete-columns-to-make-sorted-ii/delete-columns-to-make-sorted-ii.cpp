class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        vector<bool>order(n-1,0);
        int ans=0;
        for(int i=0;i<m;++i) 
        {
            bool flag=0;
            for(int j=0;j+1<n;++j) 
            {
                if(!order[j] && strs[j][i]>strs[j+1][i]) 
                {
                    flag=1;
                    break;
                }
            }

            if(flag)
                ++ans;
            else 
            {
                for(int j=0;j+1<n;++j) 
                {
                    if(strs[j][i]<strs[j+1][i])
                        order[j]=1;
                }
            }
        }

        return ans;
    }
};