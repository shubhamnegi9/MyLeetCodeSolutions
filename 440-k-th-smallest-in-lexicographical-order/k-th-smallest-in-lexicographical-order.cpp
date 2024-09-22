class Solution {
public:
    // Approach 1: By sorting using custom comparator - TLE and MLE
    // T.C. = O(nlogn), S.C. = O(n)
    int findKthNumber1(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        
        auto comp = [&](int &num1, int &num2) {
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            return s1 < s2;
        };
        
        sort(nums.begin(), nums.end(), comp);
        return nums[k-1];
    }
    
    // Approach 2: Using Simple Recursion as DFS - TLE and MLE
    // T.C. = O(n), S.C. = O(d) for system stack and O(n) for result vector
    void solve1(int currNum, vector<int> &nums, int n) {
        // Out of range
        if(currNum > n)
            return;
        
        nums.push_back(currNum);
        
        for(int append = 0; append <= 9; append++) {
            int newNum = currNum*10 + append;
            // Out of range
            if(newNum > n)
                return;
            solve1(newNum, nums, n);
        }   
    }
    
    int findKthNumber2(int n, int k) {
        vector<int> nums;
        for(int currNum = 1; currNum <= 9; currNum++) {
            solve1(currNum, nums, n);
        }
        return nums[k-1];
    }
    
    // Approach 3: Using Simple Recursion as DFS without storing in result - TLE 
    // T.C. = O(n), S.C. = O(d) for system stack 
    bool solve2(long long currNum, int n, int k, int &count, int &result) {
        // Out of range
        if(currNum > n)
            return false;
        
        count++;
        
        if(count == k){
            result = currNum;
            return true;
        }
        
        for(int append = 0; append <= 9; append++) {
            long long newNum = currNum*10 + append;
            // Out of range
            if(newNum > n)
                break;              // break here and not return!
            
            if(solve2(newNum, n, k, count, result))
                return true;
        }   
        
        return false;
    }
    
    int findKthNumber3(int n, int k) {
        int result = 0;
        int count = 0;
        for(int currNum = 1; currNum <= 9; currNum++) {
            // Once we get the kth lexicographically smallest integer, break from loop to skip checking for next numbers
            if(solve2(currNum, n, k, count, result))
                break;
        }
        return result;
    }
    
    // Approach 4: Optimal Appraoach
    //T.C : O((logn)^2)
    //S.C : O(log(n)) system resursion stack
    int Count(long curr, long next, int n) {
        int countNum = 0;
        while(curr <= n) {
            countNum += (next-curr);
            curr *= 10;
            next *= 10;
            next = min(next, long(n+1));
        }
        return countNum;
    }
    
    int findKthNumber4(int n, int k) {
        int curr = 1;
        k-=1;   //Since we start from the first number (1), we need k-1 more numbers
            
        while(k > 0) {
            // Count of elements to be skipped in curr prefix tree
            int count = Count(curr, curr+1, n);
            
            if(count <= k) {
                // Moving to next prefix tree
                curr++;
                k-=count;   //skipping the elements under curr prefix tree
            }
            else {
                 // Moving to deeper level in same prefix tree
                curr*=10;
                k--;
            }
        }
        
        return curr;
    }
    
    int findKthNumber(int n, int k) {
        // Approach 1: By sorting usin custom comparator
        // return findKthNumber1(n, k);
        
        // Approach 2: Using Simple Recursion as DFS
        // return findKthNumber2(n, k);
        
        // Approach 3: Using Simple Recursion as DFS without storing in result
        // return findKthNumber3(n, k);
        
        // Approach 4: Optimal Appraoach
        return findKthNumber4(n, k);
    }
};