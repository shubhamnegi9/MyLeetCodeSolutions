class Solution {
public:
    void rotateArray1(vector<int>& arr, int k, int n) {
        k = k%n;

        vector<int> temp;

        for(int i = n-k; i < n; i++) {
            temp.push_back(arr[i]);
        }

        for(int i = n-k-1; i >= 0; i--) {
            arr[i+k] = arr[i];
        }

        for(int i = 0; i < k; i++) {
            arr[i] = temp[i];
        }
    }
    
    void rotateArray2(vector<int>& arr, int k, int n) {
        k = k%n;

        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // rotateArray1(nums, k, n);
        
        rotateArray2(nums, k, n);
    }
};