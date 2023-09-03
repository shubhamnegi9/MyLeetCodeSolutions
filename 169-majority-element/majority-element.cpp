class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int n = nums.size();
		int ele;
		int count = 0;

		// Applying Moore's Voting Algo to find majority element 'ele'
		for(int i = 0; i < n; i++) {
			
			if(count == 0) {
				count = 1;
				ele = nums[i];
			}
			else if(nums[i] == ele) {
				count++;
			}
			else {
				count--;
			}
			
		}
		
		int cnt;
		// Verifying if the 'ele' is majority element or not.
		// This can be skipped and we can return 'ele' if given that array always has majority element.
		for(int i = 0; i < n; i++) {
			if(nums[i] == ele) {
				cnt++;
			}
		}
		if(cnt > n/2) {
			return ele;
		}
		return -1;
  }
};