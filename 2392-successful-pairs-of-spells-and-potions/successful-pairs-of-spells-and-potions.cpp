class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int value:spells)
        {
            long long req=(success+value-1)/value;
            auto it=lower_bound(potions.begin(),potions.end(),req);
            ans.push_back(potions.end()-it);
        }
        return ans;
    }
};