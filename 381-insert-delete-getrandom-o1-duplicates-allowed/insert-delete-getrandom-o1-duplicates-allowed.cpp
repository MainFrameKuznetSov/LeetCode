class RandomizedCollection {
public:

    vector<int>v;
    unordered_map<int,set<int>>mp;
    int size;

    RandomizedCollection() {
        size=0;
    }
    
    bool insert(int val) {
        if(!mp.count(val))
        {
            ++size;
            mp[val].insert(size-1);
            v.push_back(val);
            return 1;
        }
        else
        {
            ++size;
            mp[val].insert(size-1);
            v.push_back(val);
            return 0;
        }
    }
    
    bool remove(int val) {
        //return 0;
        if(!mp.count(val))
            return 0;
        else
        {
            auto st=mp[val];
            int ind=*st.begin();
            int lastElement=v.back();
            mp[val].erase(ind);
            mp[lastElement].insert(ind);
            mp[lastElement].erase(size-1);
            swap(v[size-1],v[ind]);
            v.pop_back();
            --size;
            if(mp[val].size()==0)
                mp.erase(val);
            return 1;
        }
    }
    
    int getRandom() {
        int ind=rand()%size;
        return v[ind];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */