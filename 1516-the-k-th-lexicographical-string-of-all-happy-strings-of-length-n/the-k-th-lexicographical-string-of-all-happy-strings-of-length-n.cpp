class Solution {
public:

    void recur(int n,string ans,vector<string>&str)
    {
        if(ans.size()==n)
        {
            str.push_back(ans);
            return ;
        }
        for(char i='a';i<='c';++i)
        {
            if(ans.size() && ans.back()==i)
                continue;
            recur(n,ans+i,str);
        }
    }

    string getHappyString(int n, int k) {
        string ans="";
        vector<string>str;
        recur(n,ans,str);
        if(str.size()<k)
            return "";
        sort(str.begin(),str.end());
        return str[k-1];
    }
};