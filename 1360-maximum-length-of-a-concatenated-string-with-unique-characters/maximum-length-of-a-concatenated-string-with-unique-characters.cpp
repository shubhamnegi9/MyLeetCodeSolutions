class Solution {
public:

    bool hasDuplicate(string s1, string s2) {
        // Checking if s2 is having any duplicate character as s1 

        vector<int> hash(26, 0);

        for(char ch: s1) {
            // In case if characters in s1 are itself repeating like "aa", "bb", ...
            if(hash[ch-'a'] > 0)
                return true;

            // storing character's count of s1 in hash array
            hash[ch-'a']++;
        }

        for(char ch: s2) {
            // If any character in s2 is having more than 1 count in s1
            // then it is duplicate
            if(hash[ch-'a'] > 0)
                return true;
        }

        return false;
    }
    
    // Using Recursion
    int solve(vector<string> &arr, int i, string temp, int n) {
        // Base Case
        if(i >= n)
            return temp.length();   // Return length of maximum concatenated string
        
        int include = 0, exclude = 0;

        // Note: Order should not change (as temp can also be empty in beginning)
        if(hasDuplicate(arr[i], temp)) {
            // If current string in array and concatenated string has duplicate chars,
            // then always exclude the current string
            exclude = solve(arr, i+1, temp, n);
        }
        else {
            // If current string in array and concatenated string does not have duplicate chars,
            // then finding maximum length of concatenated string by including and excluding
            // current string
            exclude = solve(arr, i+1, temp, n);
            include = solve(arr, i+1, temp + arr[i], n);
        }

        // Returning maximum length by either excluding or including current string
        return max(exclude, include);
    }

    // Using Top-Down Approach (Recursion + Memoization)
    int solveMemo(vector<string> &arr, int i, string temp, int n, unordered_map<string, int> &dp) {
        // Base Case
        if(i >= n)
            return temp.length();   // Return length of maximum concatenated string
        
        // If temp found in dp map, return its maximum length 
        if(dp.find(temp) != dp.end()) {
            return dp[temp];
        }

        int include = 0, exclude = 0;

        // Note: Order should not change (as temp can also be empty in beginning)
        if(hasDuplicate(arr[i], temp)) {
            // If current string in array and concatenated string has duplicate chars,
            // then always exclude the current string
            exclude = solve(arr, i+1, temp, n);
        }
        else {
            // If current string in array and concatenated string does not have duplicate chars,
            // then finding maximum length of concatenated string by including and excluding
            // current string
            exclude = solveMemo(arr, i+1, temp, n, dp);
            include = solveMemo(arr, i+1, temp + arr[i], n, dp);
        }

        // Returning maximum length by either excluding or including current string
        // Storing maximum length of temp in dp map
        return dp[temp] = max(exclude, include);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";   // For storing the maximum length concatenated string

        // Using Recursion
        // return solve(arr, 0, temp, n);

        // Using Recursion + Memoization
        unordered_map<string, int> dp;
        return solveMemo(arr, 0, temp, n, dp);
    }
};