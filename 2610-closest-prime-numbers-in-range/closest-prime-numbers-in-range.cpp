class Solution {
public:

    vector<int>sieve(int n)
    {
        vector<bool>check(n+1,true);
        check[0]=check[1]=false;
        for(int p=2;p*p<=n;++p) 
        {
            if(check[p]) 
            {
                for(int i=p*p;i<=n;i+=p)
                    check[i]=false;
            }   
        }
        vector<int>prime;
        for(int i=2;i<=n;++i)
        {
            if(check[i])
                prime.push_back(i);
        }
        return prime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int>prime=sieve(right);
        int ptr=-1;
        for(int i=0;i<prime.size();++i)
        {
            if(prime[i]>=left)
            {
                ptr=i;
                break;
            }
        }
        int diff=INT_MAX;
        vector<int>ans={-1,-1};
        if(ptr==-1 || ptr+1>=prime.size())
            return ans;
        for(int i=ptr+1;i<prime.size();++i)
        {
            if(diff>prime[i]-prime[i-1])
            {
                ans={prime[i-1],prime[i]};
                diff=prime[i]-prime[i-1];
            }
        }
        return ans;
    }
};