class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size(),ans=n;
        for(int i=0;i<n-1;++i)
        {
            if(word[i]!=word[i+1])
                --ans;
        }
        return ans;
    }
};