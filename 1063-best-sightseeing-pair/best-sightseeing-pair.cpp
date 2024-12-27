class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> vec(n, 0);
        //vec[i] = stores the maximum value of (values[i]+i) till index i in values wala array
        vec[0] = values[0] + 0;

        for(int i = 1; i < n; i++) {
            vec[i] = max(values[i]+i, vec[i-1]);
        }

        int result = 0;

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = vec[j-1]; //max value of (values[i]+i) in left hand side

            result = max(result, x+y);
        }

        return result;
    }
};