class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        int n = chalk.size();
        
        for(int c: chalk) {
            sum+=c;
        }
        long remainingSum = k%sum;
        int index = 0;
        for(int i = 0; i < n; i++) {
            if(remainingSum >= chalk[i])
                remainingSum-=chalk[i];
            else {
                index = i;
                break;
            }
        }
        
        return index;
    }
};