class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    vector<int> findErrorNums1(vector<int>& nums, int n) {
        int repeating = -1, missing = -1;

        for(int ele = 1; ele <= n; ele++) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] == ele) {
                    count++;
                }
            }
            if(count == 0) {
                missing = ele;
            }
            else if(count == 2) {
                repeating = ele;
            }
            if(missing != -1 && repeating != -1) {
                break;
            }
        }

        return {repeating, missing};
    }

    // Better Approach
    // T.C. = O(n) + O(n)
    // S.C. = O(n) for map
    vector<int> findErrorNums2(vector<int>& nums, int n) {
        int repeating = -1, missing = -1;
        unordered_map<int, int> mpp;

        for(int& ele: nums) {
            mpp[ele]++;
        }

        for(int num = 1; num <= n; num++) {
            if(mpp[num] == 0)
                missing = num;
            else if(mpp[num] == 2)
                repeating = num;
            if(missing != -1 && repeating != -1) {
                break;
            }
        }

        return {repeating, missing};
    }

    // Optimal Approach using sum
    vector<int> findErrorNums3(vector<int>& nums, int n) {
        long long S = 0, S2 = 0;
        long long Sn = ((long long)n*(n+1))/2;
        long long S2n = ((long long)n*(n+1)*(2*n+1))/6;

        for(int&ele: nums) {
            S += ele;
            S2 += ele*ele;
        }

        int diff = S - Sn;                  // repeating-missing
        int add = (S2 - S2n)/(S - Sn);      // repeating+missing

        int repeating = (diff+add)/2;
        int missing = repeating - diff;

        return {repeating, missing};
    }
    
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        // Brute Force Approach
        // return findErrorNums1(nums, n);

        // Better Approach
        // return findErrorNums2(nums, n);

        // Optimal Approach using sum
        return findErrorNums3(nums, n);
    }
};