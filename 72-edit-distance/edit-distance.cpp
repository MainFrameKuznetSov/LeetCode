class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<int>prev(n+1,0);
        for(int i=1;i<=n;++i)
            prev[i]=i;
        for(int i=1;i<=m;++i)
        {
            vector<int>curr(n+1,0);
            curr[0]=i;
            for(int j=1;j<=n;++j)
            {
                if(word1[i-1]==word2[j-1])
                    curr[j]=prev[j-1];
                else
                    curr[j]=min(prev[j-1],min(curr[j-1],prev[j]))+1;
            }
            prev=curr;
        }
        return prev[n];
    }
};