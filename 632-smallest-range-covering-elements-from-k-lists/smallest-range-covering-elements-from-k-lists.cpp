class Solution {
public:
    
    // Brute Force Approach
    // T.C. = O(n^3)
    // S.C. = O(n)
    vector<int> smallestRange1(vector<vector<int>>& nums) {
        vector<int> mergedNums;
        for(vector<int> num: nums) {                                // O(n)
            for(int ele: num) {
                mergedNums.push_back(ele);
            }
        }
        
        int n = mergedNums.size();
        vector<int> range = {-1000000, 1000000};
        
        if(n == 1) {
            range[0] = mergedNums[0];
            range[1] = mergedNums[0];
        } else {
            
            sort(mergedNums.begin(), mergedNums.end());              // O(nlogn)
            
            for(int i = 0; i < n; i++) {                             // O(n^2)
                for(int j = i+1; j < n; j++) {
                    int start = mergedNums[i];
                    int end = mergedNums[j];

                    bool isRangeValid = true;
                    for(vector<int> num: nums) {                     // O(n)
                        bool isPresent = false;
                        for(int ele: num) {
                            if(ele >= start && ele <= end) {
                                isPresent = true;
                                break;
                            }
                        }
                        if(!isPresent) {
                            isRangeValid = false;
                            break;
                        }
                    }
                    if(isRangeValid && end - start < range[1] - range[0]) {
                        range[0] = start;
                        range[1] = end;
                    }
            }
        }
        }
        
        return range;
    }
    
    // Better Approach
    // T.C. = O(n*k)
    // S.C. = O(k)
    vector<int> smallestRange2(vector<vector<int>>& nums) {
        int k = nums.size();
        // Vector of size k such that index of vector represents the index of list in nums 
        // and values in vector represents the index of element being considered for comparision 
        // in current list
        vector<int> v(k, 0);    
        
        vector<int> range = {-1000000, 1000000};
        
        while(true) {                                           // O(n)

            int smallest = INT_MAX;
            int largest = INT_MIN;
            int minEleListIndex = 0;
            
            for(int i = 0; i < k; i++) {                        // O(k)
                int listIndex = i;  // Index of list
                int eleIndex = v[i];   // Index of current element in current list
                int element = nums[listIndex][eleIndex];  // Current element in current list
                
                if(element < smallest) {
                    smallest = element;
                    minEleListIndex = i;     // Increasing the index of the smallest element containing list
                }
                
                largest = max(largest, element);
            }
            
            if(largest - smallest < range[1] - range[0]) {
                range[0] = smallest;
                range[1] = largest;
            }

            int nextIndex = v[minEleListIndex]+1;
            // If index goes out of bound in any of the list, stop the iteration
            if(nextIndex >= nums[minEleListIndex].size()) {
                break;
            }
            
            v[minEleListIndex] = nextIndex;
        }
        
        return range;
    }
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Brute Force Approach
        // return smallestRange1(nums);
        
        // Better Approach
        return smallestRange2(nums);
    }
};