class Solution {
public:
    int balancedString(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int k=0;
        for(int i=0;i<n;++i)
        {  
            ++mp[s[i]];
            if(mp[s[i]]>n/4)
              ++k;
        }
        if(k==0) 
            return 0;
        int i=0,j=0,count=0,ans=INT_MAX;
        while(j<n)
        { 
            --mp[s[j]];
            if(mp[s[j]]>=n/4)
                ++count;
            if(count<k)
                ++j;
            else
            {
                while(count==k)
                {  // store result
                    ans=min(ans,j-i+1);
                 // Remove calculation for i
                    ++mp[s[i]];
                    if(mp[s[i]]==(n/4)+1)
                        --count;
                    ++i;
                }
            ++j;
            }
        }
        return ans;
    }
};