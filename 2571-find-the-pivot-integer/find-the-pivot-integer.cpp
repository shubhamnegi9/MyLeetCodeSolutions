class Solution {
public:
    // Approach 1:
    // Brute Force
    // T.C. = O(n^2)
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
    // T.C. = O(n)
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
    // Using 2 pointer
    // T.C. = O(n)
    int findPivot3(int n) {
        int i = 1, j = n;
        int leftSum = 1, rightSum = n;
        while(i < j) {
            if(leftSum < rightSum) {
                i++;
                leftSum+=i;
            }
            else {
                j--;
                rightSum+=j;
            }
        }
        return (leftSum == rightSum) ? i : -1;
    } 

    // Approach 4:
    // Using mathmematical formula
    // T.C. = O(1)
    int findPivot4(int n) {
        int totalSum = n*(n+1)/2;
        int pivot = sqrt(totalSum);
        return (pivot*pivot == totalSum) ? pivot : -1;
    } 

    // Approach 5:
    // Using Binary Search
    // T.C. = O(logn)
    int findPivot5(int n) {
        int totalSum = n*(n+1)/2;

        int low = 1, high = n;

        while(low <= high) {
            int pivot = (low+high)/2;
            if(pivot*pivot == totalSum) {
                return pivot;
            }
            else if(pivot*pivot < totalSum) {
                low = pivot+1;
            }
            else {
                high = pivot-1;
            }
        }

        return -1;
    }

    int pivotInteger(int n) {
        
        return findPivot5(n);
    }
};