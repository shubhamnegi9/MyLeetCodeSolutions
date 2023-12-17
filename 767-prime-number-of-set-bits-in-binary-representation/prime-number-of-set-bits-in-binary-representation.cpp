class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while(n) {
            int bit = n & 1;
            if(bit == 1)
                count++;
            n>>=1;
        }
        return count;
    }

    bool isPrime(int n) {
        if(n==1)
            return false;
        for(int i =2; i*i <= n; i++) {
            if(n%i==0)
                return false;
        }
        return true;
    }
    
    int countPrimeSetBits(int left, int right) {
        int countPrime = 0;
        for(int num = left; num <= right; num++) {
            int setBits = countSetBits(num);
            if(isPrime(setBits)) {
                countPrime++;
            }
        }
        return countPrime;
    }
};