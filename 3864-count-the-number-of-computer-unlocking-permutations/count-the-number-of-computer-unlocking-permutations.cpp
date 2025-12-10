#define ll long long
#define MOD (int)(1e9+7) 

class Solution {
public:
    int countPermutations(vector<int>& complexity) { 
        int n=complexity.size();
        ll ans=1;
        for(int i=1;i<n;++i)
        {
            if(complexity[i]<=complexity[0])
                return 0;
            ans=(ans*i)%MOD;
        }
        return ans;
    }
};