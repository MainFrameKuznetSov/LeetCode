class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        double pwr=floor(log2(n)/log2(4));
        return n==pow(4,pwr);
    }
};