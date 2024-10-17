class Solution {
public:
    // T.C. = O(n)
    // S.C. = O(n)
    int maximumSwap1(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> maxToRight(n);
        maxToRight[n-1] = n-1;
        for(int i = n-2; i >= 0; i--) {
            int rightMaxIndx = maxToRight[i+1];
            int rightMaxEle =  s[rightMaxIndx]; 
            maxToRight[i] = (s[i] > rightMaxEle) ? i : rightMaxIndx;
        }
        
        int result = num;
        for(int i = 0; i < n; i++) {
            int rightMaxIndx = maxToRight[i];
            int rightMaxEle =  s[rightMaxIndx]; 
            if(rightMaxEle > s[i]) {
                swap(s[i], s[rightMaxIndx]);
                result = stoi(s);
                return result;
            }
        }
        
        return result;
    }
    int maximumSwap(int num) {
        return maximumSwap1(num);
    }
};