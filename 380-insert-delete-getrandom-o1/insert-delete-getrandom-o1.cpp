class RandomizedSet {
public:

    vector<int>v;
    unordered_map<int,int>mp;
    int size;

    RandomizedSet() {
        size=0;
    }
    
    bool insert(int val) {
        if(!mp.count(val))
        {
            v.push_back(val);
            ++size;
            mp[val]=size-1;
            return 1;
        }
        return 0;
    }
    
    bool remove(int val) {
        if(!mp.count(val))
            return 0;
        else
        {
            int ind=mp[val],lastElement=v[size-1];
            v[ind]=lastElement;
            mp[lastElement]=ind;
            v.pop_back();
            --size;
            mp.erase(val);
        }
        return 1;
    }
    
    int getRandom() {
        int ind=rand()%size;
        return v[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */