class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        int ans=0;
        for(char c:s)
            ++freq[c-'a'];
        for(int i:freq)
        {
            if(i)
            {
                if(i&1)
                    ++ans;
                else
                    ans+=2;
            }
        }
        return ans;
    }
};