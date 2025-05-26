class MyHashSet {
public:
    unordered_map<int,bool>set;
    MyHashSet() {
        
    }
    
    void add(int key) {
        set[key]=1;
    }
    
    void remove(int key) {
        set.erase(key);
    }
    
    bool contains(int key) {
        return set.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */