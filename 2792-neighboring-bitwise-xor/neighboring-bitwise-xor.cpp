class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size(),ans=0;
        for(int i=1;i<n;++i)
        {
            if(derived[i-1]==1)
                ans=(1-ans);
        }
        if(derived[n-1]!=ans)
            return 0;
        return 1;
    }
};