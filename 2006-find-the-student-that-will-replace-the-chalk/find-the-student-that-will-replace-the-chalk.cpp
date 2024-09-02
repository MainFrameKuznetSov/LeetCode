class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long long>psum(n,0);
        psum[0]=chalk[0];
        for(int i=1;i<n;++i)
            psum[i]=psum[i-1]+chalk[i];
        chalk.clear();
        k=k%psum[n-1];
        for(int i=0;i<n;++i)
        {
            if(k<psum[i])
                return i;
            else if(k==psum[i])
                return i+1;
        }
        return -1;
    }
};