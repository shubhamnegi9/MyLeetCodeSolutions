class Solution {
public:
    // T.C. = O(nlogn)
    // S.C. = O(1)
    void sortColors1(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
    }

    // T.C. = O(n)+O(n)
    // S.C. = O(1)
    void sortColors2(vector<int>& nums, int n) {
        int count0 = 0, count1 = 0, count2 = 0;

        for(int& ele: nums) {
            if(ele == 0)
                count0++;
            else if(ele == 1)
                count1++;
            else
                count2++;
        }

        for(int i = 0; i < count0; i++) {
            nums[i] = 0;
        }
        for(int i = count0; i < count0+count1; i++) {
            nums[i] = 1;
        }
        for(int i = count0+count1; i < n; i++) {
            nums[i] = 2;
        }
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // sortColors1(nums, n);

        sortColors2(nums, n);
    }
};