class Solution {
public:
    double myPow(double x, long long n) {
        if(x==1)
            return 1;
        if(n<0)
            return 1/myPow(x,-n);
        if(n==0)
            return 1.00;
        if(n==1)
            return x;
        if(n&1)
            return x*myPow(x*x,(n-1)/2);
        else
            return myPow(x*x,n/2);
    }
};