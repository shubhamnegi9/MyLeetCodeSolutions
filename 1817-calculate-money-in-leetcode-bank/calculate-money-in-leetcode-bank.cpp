class Solution {
public:
    int totalMoney(int n) {
        int sumFirst7 = 28;
        int total = 0;
        if(n <= 7) {
            for(int i = 1; i <= n; i++) {
                total += i;
            }
            // cout << "total= " << total << endl;
        }
        else {
            int q = n/7;
            int r = n % 7;
            // cout << "q= " << q << "r= " << r << endl;
            total += sumFirst7;
            // cout << "total= " << total << endl;
            int start = 2;
            while(q-1) {
                total += 7*(start+3);
                // cout << "total= " << total << endl;
                start++;
                q--;
            }
            if(r > 0) {
                total += (r*((2*start)+(r-1)))/2;
                // cout << "total= " << total << endl;
            }
        }
        // cout << "total= " << total << endl;
        return total;
    }
};