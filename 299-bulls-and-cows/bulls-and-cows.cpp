class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp1,mp2;
        int n=secret.size(),cA=0,cB=0;
        for(int i=0;i<n;++i)
        {
            char ch=secret[i],temp=guess[i];
            if(ch==temp)
                ++cA;
            else
            {
                if(mp1[temp]>0)
                {
                    --mp1[temp];
                    ++cB;
                }
                else
                    ++mp2[temp];
                
                if(mp2[ch]>0)
                {
                    --mp2[ch];
                    ++cB;
                }
                else
                    ++mp1[ch];
            }
        }
        return to_string(cA)+"A"+to_string(cB)+"B";
    }
};