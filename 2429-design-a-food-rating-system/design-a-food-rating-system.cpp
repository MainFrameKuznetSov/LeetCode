class Comparator
{
public:
    bool operator()(const pair<string,int>&a,const pair<string,int>&b)const
    {
        if(a.second!=b.second)
            return a.second>b.second;
        return a.first<b.first;
    }
};

class FoodRatings {
public:

    unordered_map<string,pair<string,int>>foodToDetails;
    unordered_map<string,set<pair<string,int>,Comparator>>cuisineToDetails;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;++i)
        {
            cuisineToDetails[cuisines[i]].insert({foods[i],ratings[i]});
            foodToDetails[foods[i]]={cuisines[i],ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        if(foodToDetails.count(food))
        {
            int oldRating=foodToDetails[food].second;
            string cuisine=foodToDetails[food].first;
            foodToDetails[food].second=newRating;
            auto &container=cuisineToDetails[cuisine];
            auto elementToDelete=cuisineToDetails[cuisine].find({food,oldRating});
            container.erase(elementToDelete);
            container.insert({food,newRating});
        }
    }
    
    string highestRated(string cuisine) {
        return cuisineToDetails[cuisine].begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */