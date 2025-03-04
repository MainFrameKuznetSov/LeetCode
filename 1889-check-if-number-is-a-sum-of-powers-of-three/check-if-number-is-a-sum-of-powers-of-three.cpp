class Solution {
public:
    bool checkPowersOfThree(int n) {
        unordered_set<int>t;
        while(n)
        {
            int fact=(int)(log2(n)/log2(3));
            int diff=pow(3,fact);
            //n-=pow(3,fact);
            if(t.count(diff))
                return 0;
            t.insert(diff);
            n-=diff;
            //cout<<diff<<" "<<n<<"\n";
        }
        return 1;
    }
};