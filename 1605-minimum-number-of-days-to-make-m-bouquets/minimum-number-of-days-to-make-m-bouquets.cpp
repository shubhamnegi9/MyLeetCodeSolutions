class Solution {
public:

    bool isPossible(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int totalBouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) {
                count++;
            } else {
                totalBouquets += (count/k);
                count = 0;
            }
        }

        totalBouquets += (count/k); // For the remaining elements calculate totalBouquets at end

        return totalBouquets >= m;
    }

    // Brute Force Approach
    // T.C. = O(maxEle-minEle+1) * O(n)
    // S.C. = O(1)
    int minDays1(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        // Impossible case
        if((m * 1LL * k * 1LL) > n)
            return -1;

        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        for(int i = minDay; i <= maxDay; i++) {
            if(isPossible(bloomDay, i, m, k))
                return i;
        }

        return -1;
    }

    // Optimal Approach
    // T.C. = O(log(maxEle-minEle+1)) * O(n)
    // S.C. = O(1)
    int minDays2(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        // Impossible case
        if((m * 1LL * k * 1LL) > n)
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high) {
            int mid = low+(high-low)/2;

            if(isPossible(bloomDay, mid, m, k)) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return low;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // Brute Force Approach
        // return minDays1(bloomDay, m , k);

        // Optimal Approach
        return minDays2(bloomDay, m , k);
    }
};