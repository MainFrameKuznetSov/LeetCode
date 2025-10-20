class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(string s:operations)
            ans+=(s[0]=='+' || s[2]=='+')?1:-1;
        return ans;
    }
};