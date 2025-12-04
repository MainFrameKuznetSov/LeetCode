class Solution {
public:
    int countCollisions(string dir) {
        int n=dir.size(),l=0,r=n-1;
        while(l<n && dir[l]=='L')
            ++l;
        while(r>=0 && dir[r]=='R')
            --r;
        int ans=0;
        while(l<=r)
        {
            if(dir[l]=='L' || dir[l]=='R')
                ++ans;
            ++l;
        }
        return ans;
    }
};