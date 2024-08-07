class Solution {
public:
    int minimumPushes(string word) {
        vector<int>v(26,0);
        int n=word.size();
        for(int i=0;i<n;++i)
            ++v[word[i]-'a'];
        sort(v.begin(),v.end(),greater<int>());
        int ans=0,sum=0;
        for(int i=0;i<26;++i)
        {
            if(i%8==0)
                ++sum;
            ans+=(v[i]*sum);
        }
        return ans;
    }
};