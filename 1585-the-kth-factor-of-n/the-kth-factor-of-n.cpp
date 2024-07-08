class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>fact;
        int lim=sqrt(n);
        for(int i=1;i<=lim;++i)
        {
            if(n%i==0)
            {
                fact.push_back(i);
                if(i!=n/i)
                    fact.push_back(n/i);
            }
        }
        sort(fact.begin(),fact.end());
        if(k>fact.size())
            return -1;
        else
            return fact[k-1];
    }
};