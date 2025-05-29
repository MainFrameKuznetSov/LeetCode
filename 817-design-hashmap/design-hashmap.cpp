class MyHashMap {
public:

    vector<int>Map;

    MyHashMap() {
        Map=vector<int>(1e6+1,-1);
    }
    
    void put(int key, int value) {
        Map[key]=value;
    }
    
    int get(int key) {
        return Map[key];
    }
    
    void remove(int key) {
        Map[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */