class Solution {
public:
    bool isUgly(int n) {
        /*
            Note:
            1 is an Ugly Number because 1 can be written as (2^0 * 3^0 * 5^0)
        */
        while(n > 1) {
            if(n%2 == 0)
                n /= 2;     // Keep dividing by 2 if divisible by 2
            else if(n%3==0)
                n /= 3;     // Keep dividing by 3 if divisible by 3
            else if(n%5==0)
                n /= 5;     // Keep dividing by 5 if divisible by 5
            else
                return false;   // If not divisible by 2, 3 or 5 then not ugly number
        }
        
        return (n==1);      // After dividing if n becomes 1, then it is ugly number
    }
    
    // Approach 1: using Brute Force
    // T.C. = O(n * log(n))
    int nthUglyNumberBrute(int n) {
        int count = 1;
        int i = 1;
        while(count < n) {
            i++;
            if(isUgly(i)) {
                count++;   
            }
            // cout << "count= " << count << endl;
            // cout << "i= " << i << endl;
        }
        return i;
    }
    
    int nthUglyNumberOptimal(int n) {
        vector<int> arr(n+1);
        int i2 = 1, i3 = 1, i5 = 1;
        arr[1] = 1;
        for(int i = 2; i <= n; i++) {
            int i2Ugly = arr[i2]*2;
            int i3Ugly = arr[i3]*3;
            int i5Ugly = arr[i5]*5;
            int minUgly = min({i2Ugly, i3Ugly, i5Ugly});
            arr[i] = minUgly;  
            
            if(minUgly == i2Ugly)
                i2++;
            if(minUgly == i3Ugly)
                i3++;
            if(minUgly == i5Ugly)
                i5++;
        }
        
        return arr[n];
    }
    
    int nthUglyNumber(int n) {
        // Approach 1: using Brute Force
        // return nthUglyNumberBrute(n);   
        
        // Approach 2: using Optimal Approach
        return nthUglyNumberOptimal(n);
    }
};