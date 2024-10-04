class Solution {
public:
    // Approach 1: Using Sorting 
    // T.C. = o(nlogn), S.C. = O(1)
    long long dividePlayers1(vector<int>& skill) {
        int n = skill.size();
        if(n == 2) {
            return skill[0]*skill[1];
        }
        
        int sum = 0;
        for(int num: skill) {
            sum+=num;
        }
        
        int teams = n/2;     // Total teams
        int teamSum = sum/teams;        // Sum of each team
        
        sort(skill.begin(), skill.end());
        
        long long result = 0;
        for(int i = 0; i < n/2; i++) {
            if(skill[i]+skill[n-i-1] == teamSum) {
                result += (skill[i]*skill[n-i-1]);
            } else {
                return -1;
            }
        }
        
        return result;
    }
    
    // Approach 2: Using Sorting+2-Pointer
    // T.C. = o(nlogn), S.C. = O(1)
    long long dividePlayers2(vector<int>& skill) {
        int n = skill.size();
        if(n == 2) {
            return skill[0]*skill[1];
        }
        
        sort(skill.begin(), skill.end());
        
        long long result = 0;
        int i = 0, j = n-1;
        int sum = skill[i]+skill[j];
        while(i < j) {
            if(skill[i]+skill[j] != sum) {
                return -1;
            }
            result += ((long long) skill[i] * (long long) skill[j]);
            i++;
            j--;
        }
        
        return result;
    }
    
    // Approach 3: Using Counting Sort
    // T.C. = o(n), S.C. = O(n)
    long long dividePlayers3(vector<int>& skill) {
        int n = skill.size();
        if(n == 2) {
            return skill[0]*skill[1];
        }
        
        vector<int> freq(1001, 0);
        int sum = 0;
        
        for(int ele: skill) {
            freq[ele]++;
            sum+=ele;
        }
        
        int teams = n/2;     // Total teams
        
        if(sum%teams != 0) {    // Not possible to divide players into teams of equal skill
            return -1;
        }
        
        int teamSum = sum/teams;        // Sum of each team
        
        long long result = 0;
        for(int i = 0; i < n; i++) {
            int first = skill[i];
            int second = teamSum-skill[i];
            if(freq[second] <= 0) {
                return -1;
            }
            
            result += ((long long) first * (long long) second);
            freq[second]--;
        }
        
        return result/2;
    }
    
    long long dividePlayers(vector<int>& skill) {
        // Approach 1: Using Sorting 
        // return dividePlayers1(skill);
        
        // Approach 2: Using Sorting+2-Pointer
        // return dividePlayers2(skill);
        
        // Approach 3: Using Counting Sort
        return dividePlayers3(skill);
    }
};