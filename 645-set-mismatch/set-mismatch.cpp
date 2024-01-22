class Solution {
public:
    // Better Approach Using hashing
    // T.C. = O(2n), S.C. = O(n)
    vector<int> findErrorNumsBetter(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1);
        for(int i = 0; i < n; i++) { 
            hash[nums[i]]++;
        }

        int repeating = -1, missing = -1;
        for(int i = 1; i <=n; i++) {
            if(hash[i] == 2)
                repeating = i;
            if(hash[i] == 0)
                missing = i;
            
            if(repeating != -1 && missing != -1)
                break;
        }
        return {repeating, missing};
    }

    // Optimal Approach
    vector<int> findErrorNumsOptimal(vector<int>& nums) {
        int n = nums.size();
        long long Sn = n*(n+1)/2;
        long long S2n = ((long long)n * (long long)(n+1) * (long long)(2*n+1))/6;

        long long S = 0, S2 = 0;
        for(int i = 0; i < n; i++) {
            S += nums[i];
            S2+= (long long)nums[i] * (long long)nums[i];
        }
        long long diff = S - Sn;              // repeating - missing
        long long add = (S2 - S2n) / diff;    // repeating + missing
        long long repeating = (diff + add)/2;
        long long missing = repeating - diff;
        return {(int) repeating,  (int) missing};

    }

    vector<int> findErrorNums(vector<int>& nums) {
        // Better Approach
        // return findErrorNumsBetter(nums);

        // Optimal Approach
        return findErrorNumsOptimal(nums);
    }
};