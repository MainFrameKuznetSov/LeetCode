class LockingTree {
public:

    vector<vector<int>>children;
    vector<int>prnt;
    vector<bool>locked;
    vector<int>users;

    LockingTree(vector<int>& parent) {
        prnt=parent;
        int n=parent.size();
        children.resize(n);
        locked.resize(n,0);
        users.resize(n,0);
        for(int i=1;i<n;++i)
            children[parent[i]].push_back(i);
    }
    
    bool lock(int num, int user) {
        if(locked[num])
            return 0;
        locked[num]=1;
        users[num]=user;
        return 1;
    }
    
    bool unlock(int num, int user) {
        if(!locked[num] || users[num]!=user)
            return 0;
        locked[num]=0;
        users[num]=0;
        return 1;
    }
    
    bool isParentLocked(int num)
    {
        while(num!=-1)
        {
            if(locked[num])
                return 1;
            num=prnt[num];
        }
        return 0;
    }

    bool isChildLocked(int num)
    {
        if(locked[num])
            return 1;
        for(int child:children[num])
        {
            if(isChildLocked(child))
                return 1;
        }
        return 0;
    }

    void unlockChildren(int num)
    {
        if(locked[num])
        {
            locked[num]=0;
            users[num]=0;
        }
        for(int child:children[num])
            unlockChildren(child);
    }

    bool upgrade(int num, int user) {
        if(locked[num] || isParentLocked(num) || !isChildLocked(num))
            return 0;
        unlockChildren(num);
        locked[num]=1;
        users[num]=user;
        return 1;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */