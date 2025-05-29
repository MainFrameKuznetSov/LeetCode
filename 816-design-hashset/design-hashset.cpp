class MyHashSet {
public:

    int size;
    vector<bool>Set;

    MyHashSet() {
        size=1e6+1;
        Set.resize(size);
    }
    
    void add(int key) {
        Set[key]=1;
    }
    
    void remove(int key) {
        Set[key]=0;
    }
    
    bool contains(int key) {
        return Set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */