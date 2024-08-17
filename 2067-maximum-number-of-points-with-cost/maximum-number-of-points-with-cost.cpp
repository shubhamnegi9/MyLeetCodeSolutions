class Solution {
public:
    int m, n;
    
    // Approach 1: Using Brute Force 
    // T.C. = O(m*n*n)
    // S.C. = O(n)
    long long maxPointsBrute(vector<vector<int>>& points) {
        
        vector<long long> prev(n);
        
        for(int j = 0; j < n; j++) {
            prev[j] = points[0][j]; // Storing first row elements in 'prev' vector
        }
        
        for(int i = 1; i < m; i++) {    // Starting from 1st row
            vector<long long> curr(n, 0);   // Vector for storing max. points in current row
            for(int j = 0; j < n; j++) {    // Iterating on current row
                for(int k = 0; k < n; k++) {    // Iterating on previous row
                    curr[j] = max(curr[j], (points[i][j] + prev[k] - abs(j-k)));
                }
            }
            prev = curr;    // For the next row, making current row vector as previous row vector
        }
        
        // Finally 'prev' vector is storing the max points in each column across all rows
        // Maximum element in 'prev' vector returns maximum points that we can achieve
        long long result = 0;
        for(int j = 0; j < n; j++) {
            result = max(result, prev[j]);
        }
        
        return result;  // OR : return *max_element(prev.begin(), prev.end());
    }
    
    // Approach 2: Optimal Approach
    long long maxPointsOptimal(vector<vector<int>>& points) {
        
        vector<long long> prev(n);
        
        for(int j = 0; j < n; j++) {    
            prev[j] = points[0][j]; // Storing first row elements in 'prev' vector
        }
        
        for(int i = 1; i < m; i++) {    // Starting from 1st row
            vector<long long> left(n, 0);   // vector for storing the max. points received from the prev columns towards left
            vector<long long> right(n, 0);  // vector for storing the max. points received from the prev columns towards right
            
            left[0] = prev[0];  
            for(int j = 1; j < n; j++) {
                left[j] = max(prev[j], left[j-1]-1);
            }
            
            right[n-1] = prev[n-1];
            for(int j = n-2; j >= 0; j--) {
                right[j] = max(prev[j], right[j+1]-1);
            }
            
            // Finding max. points in current column and storing in 'curr' vector
            vector<long long> curr(n, 0);
            for(int j = 0; j < n; j++) {
                curr[j] = points[i][j] + max(left[j], right[j]);
            }
            
            prev = curr;    // For the next row, making current row vector as previous row vector
        }
        
        // Finally 'prev' vector is storing the max points in each column across all rows
        return *max_element(prev.begin(), prev.end());
    }
    
    long long maxPoints(vector<vector<int>>& points) {
        m = points.size();
        n = points[0].size();
        
        // Approach 1: Brute Force 
        // return maxPointsBrute(points);
        
        // Approach 2: Optimal Approach
        return maxPointsOptimal(points);
    }
};