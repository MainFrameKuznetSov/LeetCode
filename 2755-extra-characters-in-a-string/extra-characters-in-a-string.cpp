class Solution {
public:
    unordered_map<string,int>mp;
    unordered_map<string,int>dp;
    int recur(string s)
    {
        if(s.size()==0)
            return 0;
        if(dp.find(s)!=dp.end())
            return dp[s];
        int temp=INT_MAX;
        string ns="";
        for(int i=0;i<s.size();++i)
        {
            ns+=s[i];
            if(mp.find(ns)!=mp.end())
                temp=min(temp,recur(s.substr(i+1)));
        }
        temp=min(temp,recur(s.substr(1))+1);
        dp[s]=temp;
        return temp;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto iter:dictionary)
            ++mp[iter];
        return recur(s);
    }
};