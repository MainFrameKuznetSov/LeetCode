class Solution {
public:

    int recur(vector<int>&frq)
    {
        int ans=0;
        for(int i=0;i<26;++i)
        {
            if(frq[i])
            {
                ++ans;
                --frq[i];
                ans+=recur(frq);
                ++frq[i];
            }
        }
        return ans;
    }

    int numTilePossibilities(string tiles) {
        vector<int>frq(26,0);
        for(char c:tiles)
            ++frq[c-'A'];
        return recur(frq);
    }
};