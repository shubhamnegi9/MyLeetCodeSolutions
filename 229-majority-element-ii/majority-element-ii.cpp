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
        set<int> st;
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int ele: nums) {
            mp[ele]++;
            if(mp[ele] > n/3) {
                st.insert(ele);
            }
        }

        vector<int> result(st.begin(), st.end());
        return result;
    }

    // vector<int> majorityElement3(vector<int>& nums) {
    
    // }
    
    vector<int> majorityElement(vector<int>& nums) {
        return majorityElement1(nums);

        // return majorityElement2(nums);

        // return majorityElement3(nums);
    }
};