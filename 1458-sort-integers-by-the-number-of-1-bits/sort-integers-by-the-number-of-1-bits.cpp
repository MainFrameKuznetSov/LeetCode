class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>pr;
        for(int i:arr)
            pr.push_back({i,__builtin_popcount(i)});
        sort(arr.begin(),arr.end(),[&](int a,int b)
        {
            int bitA=__builtin_popcount(a),bitB=__builtin_popcount(b);
            if(bitA!=bitB)
                return bitA<bitB;
            return a<b;
        });
        return arr;
    }
};