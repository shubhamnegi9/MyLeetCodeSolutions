class Solution {
public:
    
    //T.C : O(n * maxNum)
    //S.C : O(1000) ~ O(1)
    
    void sieve(vector<bool> &isPrime) {     // O(1000)
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i = 2; i*i < 1000; i++) {
            if(isPrime[i] == true) {
                for(int p = i*i; p < 1000; p+=i) {
                    isPrime[p] = false;
                }
            }
        }
    }
    
    bool primeSubOperation(vector<int>& nums) {
        
        // Find all prime numbers till 1000 using Sieve of Eratosthenes
        vector<bool> isPrime(1000, true);
        sieve(isPrime);
        
        // isPrime[i] == true means, i is a prime number else i is no a prime number
        
        int n = nums.size();
        for(int i = n-2; i >= 0; i--) {     // O(n)
            if(nums[i] >= nums[i+1]) {
                
                // decrease nums[i] atleast less than nums[i+1]
                for(int p = 2; p < nums[i]; p++) {  // p strictly less than nums[i] as per problem      // O(maxNum)
                    if(isPrime[p] && nums[i]-p < nums[i+1]) {
                        nums[i]-=p;
                        break;
                    }
                }
            }
            
            if(nums[i] >= nums[i+1]) {
                // If this condition is still true, it means we could not find any value of prime p such that
                // it arranged the current number in strictly increasing order
                return false;
            }
        }
        
        return true;
    }
};