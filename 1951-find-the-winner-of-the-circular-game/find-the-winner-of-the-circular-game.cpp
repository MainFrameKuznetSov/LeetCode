class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool>vect(n,true);
        int ptr=0;
        for(int i=1;i<n;++i)
        {
            int c=0;
            while(true)
            {
                if(vect[ptr]==true)
                    ++c;
                if(c==k)
                {
                    vect[ptr]=false;
                    break;
                }
                ptr=(ptr+1)%n;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(vect[i]==true)
                return i+1;
        }
        return -1;
    }
};