class Bank {
private:
    vector<long long>balance;
    int size;
public:
    Bank(vector<long long>& balance) {
        this->balance=balance;
        size=balance.size();
    }
    
    bool transfer(int acc1, int acc2, long long money) {
        if(acc1<1 || acc1>size || acc2<1 || acc2>size || balance[acc1-1]<money)
            return 0;
        balance[acc1-1]-=money;
        balance[acc2-1]+=money;
        return 1;
    }
    
    bool deposit(int acc, long long money) {
        if(acc<1 || acc>size)
            return 0;
        balance[acc-1]+=money;
        return 1;
    }
    
    bool withdraw(int acc, long long money) {
        if(acc<1 || acc>size || balance[acc-1]<money)
            return 0;
        balance[acc-1]-=money;
        return 1;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */