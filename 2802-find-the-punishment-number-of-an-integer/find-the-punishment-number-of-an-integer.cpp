class Solution {
public:

    bool hobe(string n,int ind,int tar)
    {
        if(ind==n.size())
            return tar==0;
        int s=0;
        for(int i=ind;i<n.size();++i)
        {
            s=s*10+(n[i]-'0');
            if(s>tar)
                break;
            if(hobe(n,i+1,tar-s))
                return 1;
        }
        return 0;
    }

    int punishmentNumber(int n) {
        int s=0;
        for(int i=1;i<=n;++i)
        {
            if(hobe(to_string(i*i),0,i))
                s+=(i*i);
        }
        return s;
    }
};