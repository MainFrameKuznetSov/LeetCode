class LRUCache {
public:

    int size;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    list<int>dll;// Doubly Linked List

    LRUCache(int capacity) {
        size=capacity;
    }
    
    void makeRecent(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }

    int get(int key) {
        if(mp.count(key))
        {
            makeRecent(key);
            return mp[key].second;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            mp[key].second=value;
            makeRecent(key);
        }
        else
        {
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            --size;
        }
        if(size<0)
        {
            int key_del=dll.back();
            mp.erase(key_del);
            dll.pop_back();
            ++size;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */