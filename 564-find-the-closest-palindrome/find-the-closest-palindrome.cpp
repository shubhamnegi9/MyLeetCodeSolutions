class Solution {
public:
    
    long firstHalfToPalindrome(long halfNum, bool isEven) {
        long result = halfNum;
        if(!isEven) {
            halfNum /= 10;  // For skipping the middle number to be mirrored in case original num is of odd length. 
                            // For eg: 123 -> 12321
        }
        
        // Mirroring the first half on other side
        while(halfNum > 0) {
           int rem = halfNum%10;
           result = (result*10)+rem; 
           halfNum/=10; 
        }
        
        return result;
    } 
    
    string nearestPalindromic(string s) {
        int L = s.length();
        int halfLength = (L%2==0) ? L/2 : (L/2)+1;
        long firstHalf = stol(s.substr(0, halfLength));
        
        /*
          Generate possible palindromic candidates:
          1. Palindrome by mirroring the first half.
          2. Palindrome by mirroring the first half + 1.
          3. Palindrome by mirroring the first half - 1.
          4. Handle edge cases by considering palindromes of the form 999...
             and 100...001
        */
        vector<long> possibleResults;
        possibleResults.push_back(firstHalfToPalindrome(firstHalf, L%2==0));
        possibleResults.push_back(firstHalfToPalindrome(firstHalf+1, L%2==0));
        possibleResults.push_back(firstHalfToPalindrome(firstHalf-1, L%2==0));
        // Cases like: 99, 999, 9999, ....
        possibleResults.push_back((long)pow(10, L)+1);
        // Cases like: 101, 1001, 10001, ....
        possibleResults.push_back((long)pow(10, L-1)-1);
        
        long originalNum = stol(s);
        long minDiff = LONG_MAX;
        long closest = 0;
        for(long &num: possibleResults) {
            cout << num << endl;
            // Skipping same palindrome
            if(num == originalNum)
                continue;
            
            long diff = abs(num - originalNum);
            // Finding closest palindrome
            if(diff < minDiff) {
                minDiff = diff;
                closest = num;
            }
            // Else If tie between 2 palindromes, return the smallest one
            else if(diff == minDiff) {
                closest = min(closest, num);
            }
        }
        
        return to_string(closest);  // Converting long/int to string using to_string()
    }
};