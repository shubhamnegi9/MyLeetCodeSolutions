class Solution {
public:
    
    vector<int> majorityElement1(vector<int>& nums) {
        set<int> st;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = i; j < n; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                    if(count > n/3) {
                        st.insert(nums[j]);
                    }
                }
            }
        }

        vector<int> result(st.begin(), st.end());
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
    
    vector<int> majorityElement(vector<int>& nums) {
        // return majorityElement1(nums);

        return majorityElement2(nums);
    }
};