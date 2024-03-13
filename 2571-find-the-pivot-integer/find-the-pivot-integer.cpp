class Solution {
public:
    // Approach 1:
    // Brute Force
    int findPivot1(int n) {
        for(int pivot = 1; pivot <= n; pivot++) {
            int leftSum = 0, rightSum = 0;

            for(int i = 1; i <= pivot; i++) {
                leftSum+=i;
            } 
            for(int i = pivot; i <= n; i++) {
                rightSum+=i;
            }
            if(leftSum == rightSum)
                return pivot;
        }
        return -1;
    } 

    // Approach 2:
    // Using sum of first n numbers formula
    int findPivot2(int n) {
        int total = n*(n+1)/2;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum+=i;
            if(sum == total-sum+i)
                return i;
        }
        return -1;
    } 

    // Approach 3:
    // Using mathmematical formula
    int findPivot3(int n) {
        int totalSum = n*(n+1)/2;
        int pivot = sqrt(totalSum);
        return (pivot*pivot == totalSum) ? pivot : -1;
    } 

    // // Approach 4: 
    // int findPivot4(int n) {
        
    // } 

    // // Approach 5:
    // int findPivot5(int n) {
        
    // }

    int pivotInteger(int n) {
        
        return findPivot3(n);
    }
};