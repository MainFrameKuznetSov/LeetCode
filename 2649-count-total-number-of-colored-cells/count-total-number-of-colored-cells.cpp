class Solution {
public:
    long long coloredCells(int n) {
        return 1+((long long)((long long)n*(n-1)*2));
    }
};