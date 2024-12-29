class Solution {
public:
    
    vector<int> majorityElement1(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(result.empty() || nums[i] != result[0]) {
                int count = 0;
                for(int j = i; j < n; j++) {
                    if(nums[j] == nums[i]) {
                        count++;
                    }
                }
                if(count > n/3) {
                    result.push_back(nums[i]);
                }
                if(result.size() == 2) {
                    break;
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }

    vector<int> majorityElement2(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> mp;

        for(int ele: nums) {
            mp[ele]++;
            if(mp[ele] == (n/3)+1) {
                result.push_back(ele);
            }
            if(result.size() == 2) {
                break;
            }
        }

        sort(result.begin(), result.end());
        return result;
    }

    vector<int> majorityElement3(vector<int>& nums) {
        int n = nums.size();
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int count1 = 0, count2 = 0;
        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(count1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && nums[i] != ele1) {
                ele2 = nums[i];
                count2 = 1;
            }
            else if(nums[i] == ele1) {
                count1++;
            }
            else if(nums[i] == ele2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele1) {
                count1++;
            }
            if(nums[i] == ele2) {
                count2++;
            }
        }
        if(count1 >= (n/3)+1)
            result.push_back(ele1);
        if(count2 >= (n/3)+1)
            result.push_back(ele2);

        return result;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        // return majorityElement1(nums);

        // return majorityElement2(nums);

        return majorityElement3(nums);
    }
};