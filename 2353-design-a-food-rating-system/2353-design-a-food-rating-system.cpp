#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

class FoodRatings {
    unordered_map<string, pair<string, int>> foodInfo;
    unordered_map<string, set<pair<int, string>>> cuisineMap;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        cuisineMap[cuisine].erase({-oldRating, food});
        cuisineMap[cuisine].insert({-newRating, food});
        foodInfo[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};
