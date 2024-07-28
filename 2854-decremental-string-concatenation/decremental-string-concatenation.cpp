class Solution {
public:
    int solve(int i,int &n,vector<string>&words,unordered_map<int,unordered_map<char,unordered_map<char,int>>>&dp,char f,char b)
    {
        if(i>=n)
            return 0;
        if(dp.count(i) && dp[i].count(f) && dp[i][f].count(b))
            return dp[i][f][b];
        int ans1=0,ans2=0;
        if(words[i][words[i].size()-1]==f)
            ans1=solve(i+1,n,words,dp,words[i][0],b)+words[i].size()-1;
        else
            ans1=solve(i+1,n,words,dp,words[i][0],b)+words[i].size();        
        if(words[i][0]==b)
            ans2=solve(i+1,n,words,dp,f,words[i][words[i].size()-1])+words[i].size()-1;
        else
            ans2=solve(i+1,n,words,dp,f,words[i][words[i].size()-1])+words[i].size();
        return dp[i][f][b]=min(ans1,ans2);
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        int n=words.size();
        if(n==1)
            return words[0].size();
        unordered_map<int,unordered_map<char,unordered_map<char,int>>>mp;
        return solve(1,n,words,mp,words[0][0],words[0][words[0].size()-1])+words[0].size();
    }
};