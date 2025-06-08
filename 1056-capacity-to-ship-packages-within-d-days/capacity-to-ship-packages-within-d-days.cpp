class Solution {
public:

    int requiredDays(vector<int>& weights, int capacity) {
        int days = 1, load = 0;

        for(int weight: weights) {
            if(load + weight > capacity) {
                // If beyond capacity, then increase the day and start with new load
                days++;
                load = weight;
            } else {
                // If within capacity, then increase the load
                load += weight;
            }
        }

        return days;
    }
    
    // Brute Force Approach
    // T.C. = O(sum-maxEle+1) * O(n)
    // S.C. = O(1)
    int shipWithinDays1(vector<int>& weights, int days) {
        int minRange = *max_element(weights.begin(), weights.end());
        int maxRange = accumulate(weights.begin(), weights.end(), 0);   // Find sum of all in weights

        for(int i = minRange; i <= maxRange; i++) {
            if(requiredDays(weights, i) <= days) {
                return i;
            }
        }

        return -1;
    }

    // Optimal Approach
    // T.C. = O(log(sum-maxEle+1)) * O(n)
    // S.C. = O(1)
    int shipWithinDays2(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);   // Find sum of all in weights
        // int ans = 0;
        
        while(low <= high) {
            int mid = low+(high-low)/2;

            if(requiredDays(weights, mid) <= days) {
                // ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return low; // low will point to least capacity of ship
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // Brute Force Approach
        // return shipWithinDays1(weights, days);

        // Optimal Approach
        return shipWithinDays2(weights, days);
    }
};