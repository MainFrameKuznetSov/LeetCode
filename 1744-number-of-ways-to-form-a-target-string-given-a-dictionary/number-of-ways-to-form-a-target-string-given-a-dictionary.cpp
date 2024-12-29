class Solution {
public:

    int MOD=1e9+7;

    int numWays(vector<string>& words, string target) 
    {
        vector<vector<long long>>frq(words[0].size(),vector<long long>(26,0));
        for(auto it:words)
        {
            for(int i=0;i<words[0].size();++i)
                ++frq[i][it[i]-'a'];
        }
        vector<long long>prev(target.size(),0);
        prev[0]=frq[0][target[0]-'a'];
        for(int i=1;i<words[0].size();++i)
        {
            vector<long long>curr(target.size(),0);
            curr[0]=(prev[0]+frq[i][target[0]-'a'])%MOD;
            for(int j=1;j<target.size();++j)
                curr[j]=(prev[j]+(prev[j-1]*frq[i][target[j]-'a'])%MOD)%MOD;
            prev=curr;
        }
        return prev[target.size()-1];
    }
};