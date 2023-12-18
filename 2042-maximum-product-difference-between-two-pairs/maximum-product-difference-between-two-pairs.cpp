class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for(auto ele: nums) {
            if(ele > largest) {
                secondLargest = largest;
                largest = ele;
            }
            else {
                secondLargest = max(secondLargest, ele);
            }

            if(ele < smallest) {
                secondSmallest = smallest;
                smallest = ele;
            }
            else {
                secondSmallest = min(secondSmallest, ele);
            }
        }

        return (largest * secondLargest) - (smallest * secondSmallest);
    }
};