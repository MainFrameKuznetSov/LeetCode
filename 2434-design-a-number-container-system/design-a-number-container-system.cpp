class NumberContainers {
public:

    const int n=1e6;
    map<int,set<int>>num_ind;
    map<int,int>ind_num;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ind_num.find(index)!=ind_num.end())
        {
            int temp=ind_num[index];
            num_ind[temp].erase(index);
            if(num_ind[temp].size()==0)
                num_ind.erase(temp);
        }
        ind_num[index]=number;
        num_ind[number].insert(index);
    }
    
    int find(int number) {
        if(num_ind.count(number))
            return *(num_ind[number].begin());
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */