class CustomStack {
public:
    vector<int>stk;
    int top=-1;
    CustomStack(int maxSize) {
        stk.resize(maxSize);
        top=-1;
    }
    
    void push(int x) {
        if(top==stk.size()-1)
            return ;
        ++top;
        stk[top]=x;
    }
    
    int pop() {
        if(top==-1)
            return -1;
        else
            return stk[top--];
    }
    
    void increment(int k, int val) {
        if(k>top+1)
        {
            for(int i=top;i>=0;--i)
                stk[i]+=val;
        }
        else
        {
            for(int i=0;i<k;++i)
                stk[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */