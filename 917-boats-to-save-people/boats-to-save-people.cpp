class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        
        // Sorting peoples on boat according to weights
        sort(people.begin(), people.end());
        
        // Taking 2 pointers pointing at lightest and heaviest persons
        int i = 0, j = n-1;
        
        int boats = 0;
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                // Making both people sit on the boat
                i++;
                j--;
            }
            else {
                // Making heavier person sit on the boat greedily
                j--;
            }
            boats++;
        }
        
        return boats;
    }
};