class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    vector<int> dailyTemperaturesBrute(vector<int>& temp) {
        vector<int> answer;
            int n = temp.size();
            for(int i = 0; i < n; i++) {
                int daysToWait = -1;
                for(int j = i+1; j < n; j++) {
                    if(temp[j] > temp[i]) {
                        daysToWait = j-i;
                        answer.push_back(daysToWait);
                        break;
                    }
                }
                if(daysToWait == -1)
                    answer.push_back(0);
            }
        return answer;
    }

    // Optimal Approach Using Stack
    // T.C. = O(n)  (Because every element is push and pop only once in stack)
    vector<int> dailyTemperaturesOptimal(vector<int>& temp) {
        stack<int> st;  // Stack for storing indexes of temp
        int n = temp.size();
        vector<int> answer(n);

        for(int i = n-1; i >= 0; i--) {
            // Keep popping from stack until element at top of stack is smaller than current element
            while(!st.empty() && temp[i] >= temp[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                answer[i] = 0;
            }
            else {
                answer[i] = st.top() - i;
            }

            st.push(i);
        }

        return answer;
    }

    vector<int> dailyTemperatures(vector<int>& temp) {
        
        // return dailyTemperaturesBrute(temp);

        return dailyTemperaturesOptimal(temp);
    }
};