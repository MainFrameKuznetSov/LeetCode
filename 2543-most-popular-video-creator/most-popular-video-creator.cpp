class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,pair<string,pair<long long,int>>>mp;
        int n=creators.size();
        for(int i=0;i<n;++i)
        {
            if(!mp.count(creators[i]))
                mp[creators[i]]={ids[i],{views[i],views[i]}};
            else
            {
                mp[creators[i]].second.first+=(long long)views[i];
                if(views[i]>mp[creators[i]].second.second)
                    mp[creators[i]].first=ids[i];
                else if(views[i]==mp[creators[i]].second.second)
                    mp[creators[i]].first=min(ids[i],mp[creators[i]].first);
                mp[creators[i]].second.second=max(mp[creators[i]].second.second,views[i]);
            }
        }
        vector<pair<string,pair<string,long long>>>v;
        for(auto it:mp)
        {
            //cout<<it.first<<"->{"<<it.second.first<<",{"<<it.second.second.first<<","<<it.second.second.second<<"}}\n";
            v.push_back({it.first,{it.second.first,it.second.second.first}});    
        }
        sort(v.begin(),v.end(),[&](auto &a,auto &b)
        {
            return a.second.second>b.second.second;
        }
        );
        vector<vector<string>>ans;
        ans.push_back({v[0].first,v[0].second.first});
        n=v.size();
        for(int i=1;i<n;++i)
        {
            if(v[i].second.second<v[i-1].second.second)
                break;
            ans.push_back({v[i].first,v[i].second.first});
        }
        return ans;
    }
};