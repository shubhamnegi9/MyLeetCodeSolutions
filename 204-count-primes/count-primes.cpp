class Solution {
public:
    bool isPrime(int n) {
        if(n == 1)
            return false;

        for(int i = 2; i*i <= n; i++) {
            if(n%i == 0)
                return false;
        }

        return true;
    }

    // Brute Force Approach
    // T.C. = O(n*sqrt(n))
    // S.C. = O(1)
    int countPrimes1(int n) {
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(isPrime(i))
                count++;
        }
        return count;
    }
    
    // Optimal Approach (Sieve of Eratosthenes)
    // T.C. = O(n) + O(nloglogn) + O(n)
    // S.C. = O(n) for primes array
    int countPrimes2(int n) {
        int count = 0;
        vector<int> primes(n);

        for(int i = 2; i < n; i++) {
            primes[i] = 1;
        }

        for(int i = 2; i*i < n; i++) {
            if(primes[i] == 1) {
                for(int j = i*i; j < n; j+=i) {
                    primes[j] = 0;
                }
            }
        }

        for(int i = 2; i < n; i++) {
            if(primes[i])
                count++;
        }

        return count;
    }
    
    int countPrimes(int n) {
        // Brute Force Approach
        // return countPrimes1(n);

        // Optimal Approach (Sieve of Eratosthenes)
        return countPrimes2(n);
    }
};