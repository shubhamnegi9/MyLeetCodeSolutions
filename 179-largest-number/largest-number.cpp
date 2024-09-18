class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        // Custom Comparator using Lambda Function
        auto myComparator = [] (int &num1, int &num2) {
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            return s1+s2 > s2+s1;           // Compares the numbers after concatenating them as string
        };
        
        sort(nums.begin(), nums.end(), myComparator);   // Sorts the numbers based on custom comparator to get largest number 
        
        // Corner Case
        // If after sorting, first element is 0, then largest number will always be "0"
        if(nums[0] == 0) {
            return "0";
        }
        
        string result = "";
        for(int &num: nums) {
            result += to_string(num);
        }
        
        return result;
    }
};