class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size() == 2) {
            return skill[0]*skill[1];
        }
        
        int sum = 0;
        for(int num: skill) {
            sum+=num;
        }
        
        int parts = skill.size()/2;
        int partSum = sum/parts;
        
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        long long result = 0;
        for(int i = 0; i < n/2; i++) {
            if(skill[i]+skill[n-i-1] == partSum) {
                result += (skill[i]*skill[n-i-1]);
            } else {
                return -1;
            }
        }
        
        return result;
    }
};