class SmallestInfiniteSet {
public:

    set<int>st;
    int mn;

    SmallestInfiniteSet() {
        mn=1;
    }
    
    int popSmallest() {
        if(st.empty())
        {
            ++mn;
            return mn-1;
        }
        else
        {
            int node=*st.begin();
            if(node<=mn)
            {
                st.erase(node);
                return node;
            }
            else
            {
                ++mn;
                return mn-1;
            }
        }
    }
    
    void addBack(int num) {
        if(num<mn)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */