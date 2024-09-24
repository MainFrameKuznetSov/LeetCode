class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        for(int iter:arr1)
        {
            string temp=to_string(iter);
            string pre="";
            for(char ch:temp)
            {
                pre+=ch;
                ++mp[pre];
            }
        }
        int ans=0;
        for(int iter:arr2)
        {
            string temp=to_string(iter);
            string pre="";
            for(char ch:temp)
            {
                pre+=ch;
                if(mp.find(pre)!=mp.end())
                    ans=max(ans,(int)pre.size());
            }
        }
        return ans;
    }
};