class MyHashMap {
public:

    int size;
    vector<list<pair<int,int>>>Map;

    MyHashMap() {
        size=1e4;
        Map.resize(size);
    }
    
    void put(int key, int value) {
        int hash=key%size;
        auto &chain=Map[hash];
        for(auto &it:chain)
        {
            if(it.first==key)
            {
                it.second=value;
                return ;
            }
        }
        chain.emplace_back(key,value);
    }
    
    int get(int key) {
        int hash=key%size;
        auto &chain=Map[hash];
        if(chain.empty())
            return -1;
        for(auto it:chain)
        {
            if(it.first==key)
                return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash=key%size;
        auto &chain=Map[hash];
        for(auto it=chain.begin();it!=chain.end();++it)
        {
            if(it->first==key)
            {
                chain.erase(it);
                return ;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */