class Solution {
public:

    // T.C. = O(n), S.C. = O(n)
    // where n are number of sequential digits between low and high
    vector<int> sequentialDigitsUsingBFS(int low, int high) {
        queue<int> q;

        for(int i = 1; i <= 8; i++) {
            q.push(i);
        }

        vector<int> result;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            if(temp >= low && temp <= high) {
                result.push_back(temp);
            }

            int lastDigit = temp % 10;
            if(lastDigit+1 <= 9) {
                q.push(temp*10 + lastDigit+1);
            }
        }

        return result;
    }
    
    // T.C. = O(1), S.C. = O(1)
    vector<int> sequentialDigitsOptimal(int low, int high) {
        vector<int> allPossible = {12, 23, 34, 45, 56, 67, 78, 89,
                          123, 234, 345, 456, 567, 678, 789,
                          1234, 2345, 3456, 4567, 5678, 6789,
                          12345, 23456, 34567, 45678, 56789,
                          123456, 234567, 345678, 456789,
                          1234567, 2345678, 3456789,
                          12345678, 23456789,
                          123456789};
        
        vector<int> result;
        int n = allPossible.size();
        for(int i = 0; i < n; i++) {
            if(allPossible[i] < low) 
                continue;
            else if(allPossible[i] > high) 
                break;
            else
                result.push_back(allPossible[i]);
        }

        return  result;
    }

    vector<int> sequentialDigits(int low, int high) {
        // return sequentialDigitsUsingBFS(low, high);

        return sequentialDigitsOptimal(low, high);
    }
};