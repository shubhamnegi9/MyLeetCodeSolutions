class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int count = 0;
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < heights.size()-1; i++) {
            if(heights[i] >= heights[i+1]) {
                count++;
            }
            else {
                int diff = heights[i+1] - heights[i];
                if(ladders > 0) {
                    pq.push(diff);
                    if(pq.size() > ladders) {
                        sum+=pq.top();
                        pq.pop();
                    }
                }
                else {
                    sum+=diff;
                }

                if(sum > bricks) {
                    break;
                }
                else {
                    count++;
                }
            }
        }

        return count;
    }
};