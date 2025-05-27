class Solution {
public:
    int differenceOfSums(int n, int m) {
        int mul=1,s2=0;
        while((m*mul)<=n)
        {
            s2+=(m*mul);
            ++mul;
        }
        return (n*(n+1))/2-s2-s2;
    }
};