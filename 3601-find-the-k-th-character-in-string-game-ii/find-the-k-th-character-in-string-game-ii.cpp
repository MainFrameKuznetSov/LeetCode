class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int changes=0;
        for(int i=log2(k);i>=0;--i)
        {
            long long pwr=(1LL<<i);
            if(k>pwr)
            {
                k-=pwr;
                changes+=operations[i];
            }
        }
        return 'a'+(changes)%26;
    }
};