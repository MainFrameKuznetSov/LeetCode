class SnapshotArray {
public:

    int snapID; 
    unordered_map<int,vector<pair<int,int>>>mp;

    SnapshotArray(int length) {
        snapID=0;
        for(int i=0;i<length;++i)
            mp[i].push_back({0,0});
    }
    
    void set(int index, int val) {
        mp[index].push_back({snapID,val});
    }
    
    int snap() {
        ++snapID;
        return snapID-1;
    }
    
    int get(int index, int snap_id) {
        int left=0,right=(int)mp[index].size()-1,ans=0;
        auto &it=mp[index];
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(it[mid].first<=snap_id)
            {
                ans=it[mid].second;
                left=mid+1;
            }
            else if(it[mid].first>snap_id)
                right=mid-1;
        }
        // auto res=upper_bound(begin(mp[index]),end(mp[index]),make_pair(snap_id,INT_MAX));
        // return prev(res)->second;
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */