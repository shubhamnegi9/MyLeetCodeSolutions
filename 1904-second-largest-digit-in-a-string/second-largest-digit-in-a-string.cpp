class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int sLargest = -1;
        for(char ch: s) {
            if(isdigit(ch)) {
                int num = ch-'0';
                if(num > largest) {
                    sLargest = largest;
                    largest =num;
                }
                else if(num < largest && num > sLargest) {
                    sLargest = num;
                }
            }
        }
        
        return sLargest;
    }
};