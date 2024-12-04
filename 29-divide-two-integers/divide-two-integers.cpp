class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans=(long long)((long long)dividend/(long long)divisor);
        //return (int)max(ans,(long long)INT_MAX);
        cout<<ans<<"\n";
        if(ans>INT_MAX)
            return INT_MAX;
        else if(ans<INT_MIN)
            return INT_MIN;
        else
            return (int)ans;
    }
};