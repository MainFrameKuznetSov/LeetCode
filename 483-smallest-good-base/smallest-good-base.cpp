class Solution {
public:
    string smallestGoodBase(string n) {
        long long num=stoll(n);
        for(int i=log2(num);i>=2;--i)
        {
            int temp=pow(num,(1.0/i));
            long long sum=1,prod=1;
            for(int j=0;j<i;++j)
            {
                prod*=temp;
                sum+=prod;
            }
            if(sum==num)
                return to_string(temp);
        }
        return to_string(num-1);
    }
};