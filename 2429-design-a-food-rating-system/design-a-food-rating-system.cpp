class FoodRatings {

// Custom comparator for storing values in set
// NOTE: By default set stores the value in increasing order 
//       but since we have defnined this custom comparator, 
//       now set will store according to this.
struct comp{
    bool operator ()(const pair<int, string> &p1, const pair<int, string> &p2) const {
        // If ratings are different then store according to decreasing order of ratings
        if(p1.first != p2.first) {
            return p1.first > p2.first;
        }
        // Otherwise store according to increasing order of food names
        return p1.second < p2.second;
    }    
};

// Mapping for food names to their ratings
unordered_map<string, int> foodToRatingMapping;
// Mapping for food names to their cuisines
unordered_map<string, string> foodToCuisineMapping;
// Mapping for cuinines to pair of {rating, foodName}
unordered_map<string, set<pair<int, string>, comp>> cuisineToFoodRatingMapping;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            // Filing the required mappings
            foodToRatingMapping[foods[i]] = ratings[i];
            foodToCuisineMapping[foods[i]] = cuisines[i];
            cuisineToFoodRatingMapping[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        // Taking out the older rating of this particular food
        int oldRating = foodToRatingMapping[food];
        // Replacing the food with its newer rating in foodToRatingMapping
        foodToRatingMapping[food] = newRating;
        // Taking out the cuisine name which is mapped to this particular food
        string cuisine = foodToCuisineMapping[food];
        // Removing the old pair of {rating, foodName} from the cuisineToFoodRatingMapping
        cuisineToFoodRatingMapping[cuisine].erase({oldRating, food});
        // Adding new pair of {rating, foodName} into the cuisineToFoodRatingMapping
        cuisineToFoodRatingMapping[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        // The custom comparator defned will keep the highest rated pair
        // {foodName, rating} in the beginning of set
        // Taking out that highest rated pair from set and returning its second value, i.e. rating
        pair<int, string> highestRatedPair = *(cuisineToFoodRatingMapping[cuisine].begin());
        return highestRatedPair.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */