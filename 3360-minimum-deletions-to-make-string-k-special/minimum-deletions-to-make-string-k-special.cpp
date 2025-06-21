class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>frq(26,0);
        for(char c:word)
            ++frq[c-'a'];
        int ans=INT_MAX;
        for(int i:frq)
        {
            int temp=0;
            for(int j:frq)
                temp+=(j>=i)?max(j-(i+k),0):j;
            ans=min(ans,temp);
        }
        return ans;
    }
};