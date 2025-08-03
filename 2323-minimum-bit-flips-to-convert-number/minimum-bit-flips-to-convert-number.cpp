class Solution {
public:
    // Using left shift operator
    int minBitFlips1(int start, int goal) {
        int count = 0;
        int ans = start ^ goal;

        for(int i = 0; i <= 31; i++) {
            if(ans & (1 << i))
                count += 1;
        }

        return count;
    }

    // Using right shift operator
    int minBitFlips2(int start, int goal) {
        int count = 0;
        int ans = start ^ goal;

        for(int i = 0; i <= 31; i++) {
            count += ((ans>>i) & 1);
        }

        return count;
    }

    int minBitFlips(int start, int goal) {
        // Using left shift operator
        // return minBitFlips1(start, goal);

        // Using right shift operator
        return minBitFlips2(start, goal);
    }
};