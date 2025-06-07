class Solution {
public:

    int findMax(vector<int>& piles) {
        int max = INT_MIN;
        for(int& ele: piles) {
            if(ele > max)
                max = ele;
        }
        return max;
    }

    long calculateTotalHour(vector<int>& piles, int k) {
        long totalHours = 0;

        for(int i = 0; i < piles.size(); i++) {
            // Convert piles[i] and k to double otherwise it will lead to integer division 
            // and ceil will not work (We can also make any one of them as double)
            totalHours += ceil((double)piles[i] / (double)k);
        }

        return totalHours;
    }

    // Brute Force Approach
    // T.C. = O(max(piles) * n), n = size of piles
    // S.C. = O(1)
    int minEatingSpeed1(vector<int>& piles, int h) {
        int max = findMax(piles);

        for(int k = 1; k <= max; k++) {
            long long totalH = calculateTotalHour(piles, k);
            if(totalH <= h) {
                return k;
            }
        }

        return -1;
    }

    // Optimal Approach
    // T.C. = O(log(max(piles)) * n), n = size of piles
    // S.C. = O(1)
    int minEatingSpeed2(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int mid = low+(high-low)/2;
            long totalH = calculateTotalHour(piles, mid);
            if(totalH <= h) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return low;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        // Brute Force Approach
        // return minEatingSpeed1(piles, h);

        // Optimal Approach
        return minEatingSpeed2(piles, h);
    }
};