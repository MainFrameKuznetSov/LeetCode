class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<0)
            return 0;
        double pwr=(floor(log10(n)/log10(3)));
        // cout<<pwr<<"\n";
        int val=(int)pow(3,pwr);
        // cout<<val<<"\n";
        return n && (val==n);
    }
};