class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(3) for set
    int totalFruit1(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            set<int> st;        // set gets reset for new starting point of subarray
            for(int j = i; j < n; j++) {
                st.insert(fruits[j]);

                if(st.size() <= 2) {
                    maxLen = max(maxLen, j-i+1);
                }
                else {
                    break;      // We won't consider length of this subarray and further subarray from this starting point
                }
            }
        }

        return maxLen;
    }

    // Better Approach
    // T.C. = O(2n)
    // S.C. = O(3)
    int totalFruit2(vector<int>& fruits) {
        int n = fruits.size(), l = 0, r = 0, maxLen = 0;
        map<int, int> mpp;

        while(r < n) {
            mpp[fruits[r]]++;

            // Shrinking of window by l times
            while(mpp.size() > 2) {
                mpp[fruits[l]]--;
                // If value in map becomes 0, then remove from map
                if(mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            if(mpp.size() <= 2) {
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }

        return maxLen;
    }
    
    int totalFruit(vector<int>& fruits) {
        // Brute Force Approach
        // return totalFruit1(fruits);

        // Better Approach
        return totalFruit2(fruits);
    }
};