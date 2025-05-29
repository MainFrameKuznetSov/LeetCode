class MyHashSet {
public:

    int size;
    vector<list<int>>Set;

    MyHashSet() {
        size=1e4;
        Set.resize(size);
    }
    
    void add(int key) {
        int hash=key%size;
        auto &chain=Set[hash];
        for(auto it:chain)
        {
            if(it==key)
                return ;
        }
        chain.emplace_back(key);
    }
    
    void remove(int key) {
        int hash=key%size;
        auto &chain=Set[hash];
        for(auto it=chain.begin();it!=chain.end();++it)
        {
            if(*it==key)
            {
                chain.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int hash=key%size;
        auto &chain=Set[hash];
        for(auto it:chain)
        {
            if(it==key)
                return 1;
        }
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */