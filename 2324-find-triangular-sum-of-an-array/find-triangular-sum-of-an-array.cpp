class Solution {
public:
    int triangularSum(vector<int>& numbers) {
        while(numbers.size() > 1) {
            int i = 0;
            vector<int> adjacentDigitsSum;
            while(i < numbers.size()-1) {
                adjacentDigitsSum.push_back((numbers[i] + numbers[i+1])%10);
                i++;
            }
            numbers = adjacentDigitsSum;
        }
        return numbers[0];
    }
};