class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size(),c=0;
        unordered_map<string,int>mp;
        for(auto iter:arr)
            ++mp[iter];
        for(auto iter:arr)
        {
            if(mp[iter]==1)
            {
                --k;
                if(k==0)
                    return iter;
            }
        }
        return "";
    }
};