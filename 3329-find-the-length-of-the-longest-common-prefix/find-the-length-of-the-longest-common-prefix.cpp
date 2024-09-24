class Solution {
public:
    // Approach 1: Using set to store all possible prefixes
    int longestCommonPrefix1(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<int> st;
        
        for(int num1: arr1) {
            // Adding all the possible prefixes of current number to set
            while(num1 > 0) {
                st.insert(num1);
                num1/=10;        // Dividing by 10 to find the prefixes of num
            }
        }
        
        int result = 0;
        
        for(int num2: arr2) {
            // Keep finding all the possible prefixes until it is not found in set,
            // otherwise we will stop the loop to skip checking for smaller prefixes
            while(!st.count(num2) && num2 > 0) {
                num2/=10;        // Dividing by 10 to find the prefixes of num2
            }
            
            if(num2 > 0) {   
                // If (num > 0), it means that we have found one of the prefixes of num2 in the set
                result = max(result, (int)(log10(num2)+1));     // (log10(num2)+1) will give number of digits in prefix
            }
        }
        
        return result;
        
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Approach 1: Using set to store all possible prefixes
        return longestCommonPrefix1(arr1, arr2);
    }
};