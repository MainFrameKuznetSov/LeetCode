class ATM {
public:

    long long tot;
    vector<int>curr,val;

    ATM() {
        tot=0LL;
        curr.assign(5,0);
        val={20,50,100,200,500};
    }
    
    void deposit(vector<int> notes) {
        for(int i=0;i<5;++i)
        {
            curr[i]+=notes[i];
            tot+=(1LL*val[i]*notes[i]);
        }
        // for(int i:curr)
        //     cout<<i<<" ";
        // cout<<"\n"<<tot<<"\n";
        return ;
    }
    
    vector<int> withdraw(int amount) {
        vector<int>ans(5);
        if(amount>tot)
            return {-1};
        int pre=amount;
        vector<int>temp=curr;
        for(int i=4;i>=0;--i)
        {
            //cout<<val[i]<<"\n";
                int cnt=(amount/val[i]);
                cnt=min(cnt,curr[i]);
                amount-=(cnt*val[i]);
                curr[i]-=cnt;
                ans[i]+=cnt;
        }
        if(amount)
        {
            curr=temp;
            return {-1};
        }
        tot-=pre;
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */