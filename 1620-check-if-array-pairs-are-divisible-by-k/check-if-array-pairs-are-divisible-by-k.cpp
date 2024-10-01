class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;++i)
        {
            int temp=arr[i]%k;
            temp=temp<0?temp+k:temp;
            ++mp[temp];
        }
        for(int i=1;i<=k/2;++i)
        {
            if(mp[i]!=mp[k-i])
                return false;
        }
        if(mp[0]&1)
            return false;
        return true;
    }
};