class Solution {
public:

    int n;
    int ans;

    void helper(string s)
    {
        int n=s.size(),cnt=1;
        for(int i=1;i<n;++i)
        {
            if(s[i]==s[i-1])
                ++cnt;
            else
            {
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
    }

    void f(int ind,string s,int k)
    {
        helper(s);
        if(ind>=n || k==0)
            return ;

        char pre=s[ind];
        if(s[ind]=='T')
            s[ind]='F';
        else    
            s[ind]='T';
        f(ind+1,s,k-1);
        s[ind]=pre;
        f(ind+1,s,k);
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int size=answerKey.size(),maxLen=0,left=0,cntFalse=0,cntTrue=0;
        // for(int right=0;right<size;++right)
        // {
        //     if(answerKey[right]=='F')
        //         ++cntFalse;
        //     while(cntFalse>k)
        //     {
        //         if(answerKey[left]=='F')
        //             --cntFalse;
        //         ++left;
        //     }
        //     maxLen=max(maxLen,right-left+1);
        // }
        // left=0;
        // for(int right=0;right<size;++right)
        // {
        //     if(answerKey[right]=='T')
        //         ++cntTrue;
        //     while(cntTrue>k)
        //     {
        //         if(answerKey[left]=='T')
        //             --cntTrue;
        //         ++left;
        //     }
        //     maxLen=max(maxLen,right-left+1);
        // }

        // return maxLen;

        for(int right=0;right<size;++right)
        {
            if(answerKey[right]=='T')
                ++cntTrue;
            else
                ++cntFalse;
            while(min(cntTrue,cntFalse)>k)
            {
                if(answerKey[left]=='T')
                    --cntTrue;
                else
                    --cntFalse;
                ++left;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};