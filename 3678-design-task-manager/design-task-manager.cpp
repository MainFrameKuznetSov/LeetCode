class TaskManager {
public:

    set<pair<int,pair<int,int>>,greater<pair<int,pair<int,int>>>>taskOrder;//{priority,{taskId,userId}}
    unordered_map<int,pair<int,int>>taskDetails;//{taskId,{priority,userId}}

    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks)
        {
            int userId=it[0],taskId=it[1],priority=it[2];
            taskOrder.insert({priority,{taskId,userId}});
            taskDetails[taskId]={priority,userId};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskOrder.insert({priority,{taskId,userId}});
        taskDetails[taskId]={priority,userId};
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority=taskDetails[taskId].first;
        int userId=taskDetails[taskId].second;
        taskOrder.erase({oldPriority,{taskId,userId}});
        taskOrder.insert({newPriority,{taskId,userId}});
        taskDetails[taskId]={newPriority,userId};
    }
    
    void rmv(int taskId) {
        int priority=taskDetails[taskId].first;
        int userId=taskDetails[taskId].second;
        taskOrder.erase({priority,{taskId,userId}});
        taskDetails.erase(taskId);
    }
    
    int execTop() {
        if(taskOrder.empty())
            return -1;
        auto top=*taskOrder.begin();
        taskOrder.erase(top);
        int priority=top.first,taskId=top.second.first,userId=top.second.second;
        taskDetails.erase(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */