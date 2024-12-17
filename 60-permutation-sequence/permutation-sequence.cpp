class Solution {
public:
    void bcktrk(vector<int>&v,string &ans,int n,int k,vector<int>&f)
    {
        if(n==1)
        {
            ans+=to_string(v.back());
            return ;
        }
        int ind=(k/f[n-1]);
        if(k%f[n-1]==0)
            --ind;
        k-=f[n-1]*ind;
        ans+=to_string(v[ind]);
        v.erase(v.begin()+ind);
        bcktrk(v,ans,n-1,k,f);
    }
    string getPermutation(int n, int k) {
        if(n==1)
            return "1";
        int fact=1;
        vector<int>f;
        f.push_back(1);
        for(int i=1;i<10;++i)
        {
            fact*=i;
            f.push_back(fact);
        }
        string ans="";
        vector<int>v;
        for(int i=1;i<=n;++i)
            v.push_back(i);
        bcktrk(v,ans,n,k,f);
        return ans;
    }
};