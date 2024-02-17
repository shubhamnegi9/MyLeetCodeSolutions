class Solution {
public:
    // DP Array for memoization
    // Although 3 variables - idx, bricks, laaders are changing in recursion but
    // we can use 2d array to uniquely identify a state
    vector<vector<int>> dp;

    // Using Recursion + Memoization
    // Since there are options to use either bricks or ladders, we can use recursion
    // This will give Memory Limit Exceed as the constraint for bricks is very large
    int solve(int idx, vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        
        // Base Case
        if(idx >= n-1) {
            return 0;
        }

        if(dp[bricks][ladders] != -1) {
            return dp[bricks][ladders];
        }

        if(heights[idx] >= heights[idx+1]) {
            // Move to next building without bricks or ladder
            return 1 + solve(idx+1, heights, bricks, ladders);
        }
        else {
            // We need bricks or ladder to move to next building
            int byBricks = 0, byLadders = 0;
            int diff = heights[idx+1] - heights[idx];

            if(bricks >= diff) {
                byBricks = 1 + solve(idx+1, heights, bricks-diff, ladders);
            }

            if(ladders > 0) {
                byLadders = 1 + solve(idx+1, heights, bricks, ladders-1);
            }

            return dp[bricks][ladders] = max(byBricks, byLadders);
        }

        return -1;
    }


    // Using Min Heap
    /*
        Iterate on the buildings, maintaining the largest r jumps (where r is number of ladders) 
        and the sum of the remaining ones so far, and stop whenever this sum exceeds number 
        of bricks.
    */
    int furthestBuildingUsingMinHeap(vector<int>& heights, int bricks, int ladders) {
        int count = 0;
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;  // Min Heap

        for(int i = 0; i < heights.size()-1; i++) {
            if(heights[i] >= heights[i+1]) {
                count++;    // Increase count of farthest building reached
            }
            else {
                int diff = heights[i+1] - heights[i];
                // Maintaining the largest r jumps (where r is number of ladders) in min heap
                if(ladders > 0) {
                    pq.push(diff);
                    if(pq.size() > ladders) {
                        sum+=pq.top();  // Adding remaining jumps in sum
                        pq.pop();
                    }
                }
                else {
                    sum+=diff;  // Adding remaining jumps in sum
                }

                if(sum > bricks) {  // stop whenever this sum exceeds number of bricks
                    break;
                }
                else {
                    count++;    // Increase count of farthest building reached
                }
            }
        }

        return count;
    }

    // Using Max Heap (Lazy Greedy Approach)
    int furthestBuildingUsingMaxHeap(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        // Max Heap
        priority_queue<int> pq;

        int i = 0;

        for(; i < n-1; i++) {
            if(heights[i] >= heights[i+1]) {
                // Move to next building without bricks or ladder
                continue;
            }
            else {
                int diff = heights[i+1] - heights[i];

                if(bricks >= diff) {
                    // If enough bricks are present to move to next building
                    bricks-=diff;
                    pq.push(diff);  // Saving bricks used in pq for future
                }
                else if(ladders > 0) {
                    if(!pq.empty()) {
                        // Checking if we have used any maximum bricks in past which we can use
                        // currently instead of ladder
                        int maxBricksInPast = pq.top();
                        if(maxBricksInPast > diff) {
                            // Maximum bricks from past can be used instead of ladder
                            bricks+=maxBricksInPast;
                            pq.pop();
                            bricks-=diff;
                            pq.push(diff);  // Saving bricks used in pq for future
                        }
                    }
                    ladders--;  // Ladder is used either in past to replace bricks or in present
                }
                else {
                    break;  // We don't have bricks or ladder anymore
                }

            }
        }

        // Returning position of maximum buiilding reached
        return i;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // Using Recursion + Memoization
        // dp = vector<vector<int>>(bricks+1, vector<int>(ladders+1, -1));
        // return solve(0, heights, bricks, ladders);

        // Using Min Heap
        // return furthestBuildingUsingMinHeap(heights, bricks, ladders);

        // Using Max Heap
        return furthestBuildingUsingMaxHeap(heights, bricks, ladders);
    }
};