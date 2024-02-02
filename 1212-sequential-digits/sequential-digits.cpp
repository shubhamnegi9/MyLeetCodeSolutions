class Solution {
public:

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

    vector<int> sequentialDigits(int low, int high) {
        return sequentialDigitsUsingBFS(low, high);
    }
};