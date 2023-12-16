class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            // Checking if arr[i] != el2 before assigning to el1
            if(cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            }
            // Checking if arr[i] != el1 before assigning to el2
            else if(cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1) {
                cnt1++;
            }
            else if(nums[i] == el2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Checking if el1 and el2 are majority element or not
        cnt1 = 0, cnt2 = 0;     // Resetting counters
        int mini = int(n/3) + 1;
        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(nums[i] == el1) 
                cnt1++;
            if(nums[i] == el2)
                cnt2++;
        }

        if(cnt1 >= mini)
            res.push_back(el1);
        if(cnt2 >= mini)
            res.push_back(el2);

        return res;
        }
};