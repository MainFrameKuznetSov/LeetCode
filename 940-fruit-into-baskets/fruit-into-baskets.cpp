class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int n=fruits.size(),l=0,r=0,ans=0;
        while(r<n)
        {
            ++mp[fruits[r]];
            if(mp.size()<=2)
                ans=max(ans,r-l+1);
            else
            {
                --mp[fruits[l]];
                if(mp[fruits[l]]==0)
                    mp.erase(fruits[l]);
                ++l;
            }
            ++r;
        }
        return ans;
    }
};