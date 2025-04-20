class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(int i:answers)
            ++mp[i];
        int ans=0;
        for(auto &[key,val]:mp)
            ans+=(val+key)/(key+1)*(key+1);
        return ans;
    }
};