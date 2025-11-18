class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size()-2;
        while(n>=0 && bits[n])
            --n;
        return (bits.size()-n)%2==0;

    }
};