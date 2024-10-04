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
        
        int teams = skill.size()/2;     // Total teams
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
    
    long long dividePlayers(vector<int>& skill) {
        // Approach 1: Using Sorting 
        // return dividePlayers1(skill);
        
        // Approach 2: Using Sorting+2-Pointer
        return dividePlayers2(skill);
    }
};