class Solution {
public:
    int possibleStringCount(string word, int k) {
        int MOD=1e9+7,cnt=1,n=word.size();
        vector<int>v;
        for(int i=0;i<n-1;++i)
        {
            if(word[i]==word[i+1])
                ++cnt;
            else
            {
                v.push_back(cnt);
                cnt=1;
            }
        }
        v.push_back(cnt);

        long long sum=1LL;
        for(int it:v)
            sum=(sum*it)%MOD;
        
        if(k<=v.size())
            return sum;

        vector<int>prev(k,0);
        prev[0]=1;

        for(int it:v)
        {
            vector<int>curr(k,0);
            long long temp=0;
            for(int j=0;j<k;++j)
            {
                if(j>0)
                    temp=(temp+prev[j-1])%MOD;
                if(j>it)
                    temp=(temp-prev[j-it-1]+MOD)%MOD;
                curr[j]=temp;
            }
            prev=curr;
        }

        long long wrong=0;
        for(int i=v.size();i<k;++i)
            wrong=(wrong+prev[i])%MOD;
        return (sum-wrong+MOD)%MOD;

    }
};