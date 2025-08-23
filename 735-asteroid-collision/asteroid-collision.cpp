class Solution {
public:
    
    vector<int> asteroidCollision1(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                while(!st.empty() && st.top() > 0  && st.top() < abs(asteroids[i])) {
                    st.pop();
                }

                if(!st.empty() && st.top() > 0 && st.top() == abs(asteroids[i])) {
                    st.pop();
                }
                else if(st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> v;      
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        } 

        reverse(v.begin(), v.end());    // Reverse the vector to get correct order 
        return v;
    }

    vector<int> asteroidCollision2(vector<int>& asteroids) {
        int n = asteroids.size();
        list<int> ls;

        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0) {
                ls.push_back(asteroids[i]);
            } else {
                while(!ls.empty() && ls.back() > 0  && ls.back() < abs(asteroids[i])) {
                    ls.pop_back();
                }

                if(!ls.empty() && ls.back() > 0 && ls.back() == abs(asteroids[i])) {
                    ls.pop_back();
                }
                else if(ls.empty() || ls.back() < 0) {
                    ls.push_back(asteroids[i]);
                }
            }
        }

        vector<int> v(ls.begin(), ls.end());
        return v;
    }
    
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // Using stack
        return asteroidCollision1(asteroids);

        // Using list
        // return asteroidCollision2(asteroids);
    }
};