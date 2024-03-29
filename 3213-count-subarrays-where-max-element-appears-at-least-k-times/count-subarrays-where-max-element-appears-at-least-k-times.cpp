class Solution {
public:
    // Approach 1: Using Sliding Window
    // T.C. = O(n), S.C. = O(1)
    long long countSubarrays1(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long res = 0;
        
        int maxEle = *max_element(nums.begin(), nums.end());
        int maxEleCount = 0;

        while(j < n) {
            if(nums[j] == maxEle) 
                maxEleCount++;   

            while(maxEleCount >= k) {
                res += (n-j); 

                if(nums[i] == maxEle) 
                    maxEleCount--;
                i++;
            }
            j++;
        }

        return res;
    }

    // Approach 2: By tracking Indexes of Max Element
    // T.C. = O(n), S.C. = O(n)
    long long countSubarrays2(vector<int>& nums, int k) {
        vector<int> maxElementIndices;
        int n = nums.size();
        long long res = 0;

        int maxEle = *max_element(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            if(nums[i] == maxEle) {
                maxElementIndices.push_back(i);
            }

            int size = maxElementIndices.size();

            if(size >= k) {
                int lastIndexOfMaxEle = maxElementIndices[size - k];
                res += (lastIndexOfMaxEle+1);
            }
        }

        return res;
    }
    
    long long countSubarrays(vector<int>& nums, int k) {

        // Approach 1: Using Sliding Window
        // return countSubarrays1(nums, k);

        // Approach 2: By tracking Indexes of Max Element
        return countSubarrays2(nums, k);
    }
};