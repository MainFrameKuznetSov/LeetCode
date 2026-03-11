class Solution {
public:
    int bitwiseComplement(int n) {
        return n==0?1:(n&(n-1))?(~n)+(1<<(int)(ceil(log2(n)))):(~n)+(1<<((int)(ceil(log2(n)))+1));
    }
};