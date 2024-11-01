class Solution {
public:
    // Using recursion
    long long solve(int ri, int pi, vector<int>& robot, vector<int>& position) {
        
        // Base Cases
        // All robots are repaired
        if(ri >= robot.size())  
            return 0;
        
        // All robots are not repaired but limit of all factories are reached
        // This is invalid case as per problem
        if(pi >= position.size())   
            return 1e12;            // Return maximum possible value
        
        long long take = abs(robot[ri] - position[pi]) + solve(ri+1, pi+1, robot, position);
        long long skip = solve(ri, pi+1, robot, position);
        
        return min(take, skip);
    }
    
    // Using Top Down Memoization approach
    // T.C. = O(m*n), m = size of robot vector, n = size of position vector
    long long solveMemo(int ri, int pi, vector<int>& robot, vector<int>& position, vector<vector<long long>>& dp) {
        
        // Base Cases
        // All robots are repaired
        if(ri >= robot.size())  
            return 0;
        
        // All robots are not repaired but limit of all factories are reached
        // This is invalid case as per problem
        if(pi >= position.size())   
            return 1e12;            // Return maximum possible value
        
        if(dp[ri][pi] != -1) {
            return dp[ri][pi];
        }
        
        long long take = abs(robot[ri] - position[pi]) + solveMemo(ri+1, pi+1, robot, position, dp);
        long long skip = solveMemo(ri, pi+1, robot, position, dp);
        
        return dp[ri][pi] = min(take, skip);
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        // Sort robot and factory vectors
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        vector<int> position;
        // Expand factory vector into position vector
        for(int i = 0; i < factory.size(); i++) {
            int pos = factory[i][0];
            int limit = factory[i][1];
            while(limit--) {
                position.push_back(pos);
            }
        }
        
        // Using recursion
        // return solve(0, 0, robot, position);
        
        // Using Top Down Memoization approach
        int m = robot.size();
        int n = position.size();
        vector<vector<long long>> dp(m+1, vector<long long> (n+1,-1));
        return solveMemo(0, 0, robot, position, dp);
        
    }
};