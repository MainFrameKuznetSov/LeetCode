class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        double num=log2(buckets);
        double den=log2(minutesToTest/minutesToDie+1);
        return (int)ceil(num/den);
    }
};