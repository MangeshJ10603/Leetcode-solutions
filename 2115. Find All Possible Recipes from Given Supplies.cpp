#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> canCook;
    unordered_map<string, int> recipeIndex;

    bool dfs(string &r, vector<vector<string>> &ingredients) {
        if (canCook.count(r)) return canCook[r];
        if (!recipeIndex.count(r)) return false;
        
        canCook[r] = false;
        for (auto &nei : ingredients[recipeIndex[r]]) {
            if (!dfs(nei, ingredients)) return false;
        }
        
        return canCook[r] = true;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for (auto &s : supplies) canCook[s] = true;
        for (int i = 0; i < recipes.size(); i++) recipeIndex[recipes[i]] = i;
        
        vector<string> result;
        for (auto &r : recipes) {
            if (dfs(r, ingredients)) result.push_back(r);
        }
        
        return result;
    }
};
