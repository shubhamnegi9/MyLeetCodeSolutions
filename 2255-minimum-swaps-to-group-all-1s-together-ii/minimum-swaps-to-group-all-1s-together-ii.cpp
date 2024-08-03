class Solution {
public:
    
    // Approach-1 (Using extra space + Khandani Sliding Window)
    int minSwapsUsingExtraSpace(vector<int>& nums) {
         int n = nums.size();
        vector<int> temp(2*n);  // Creating another array of twice the size
        
        // For appending same array at the end to handle circular array case
        for(int i = 0; i < 2*n; i++) {
            temp[i] = nums[i%n];
        }
        
        // Applying Sliding Window 
        int windowSize = count(nums.begin(), nums.end(), 1); // Window size using original nums array
        int currCountOf1s = 0;
        int maxCountOf1s = 0;
        int i = 0, j = 0;
        
        while(j < 2*n) {
            currCountOf1s+=temp[j];
            
            if(j-i+1 > windowSize) {
                // Shrink the window
                currCountOf1s-=temp[i];
                i++;
            }
            
            // Keeping track of max count of 1s for each window
            maxCountOf1s = max(maxCountOf1s, currCountOf1s);
            j++;
        }
        
        // Returning min. no. of swaps
        return (windowSize - maxCountOf1s);
    }
    
    int minSwaps(vector<int>& nums) {
        return minSwapsUsingExtraSpace(nums);
    }
};