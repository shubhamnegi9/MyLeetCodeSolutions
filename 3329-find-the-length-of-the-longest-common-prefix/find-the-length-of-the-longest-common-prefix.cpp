class Solution {
public:
    // Approach 1: Using set to store all possible prefixes
    //T.C : O(m*log10(M) + n*log10(N))
    //S.C : O(m*log10(M)) for set 
    int longestCommonPrefix1(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<int> st;
        
        for(int num1: arr1) {
            // Adding all the possible prefixes of current number to set
            while(num1 > 0) {
                st.insert(num1);
                num1/=10;        // Dividing by 10 to find the prefixes of num
            }
        }
        
        int result = 0;
        
        for(int num2: arr2) {
            // Keep finding all the possible prefixes until it is not found in set,
            // otherwise we will stop the loop to skip checking for smaller prefixes
            while(!st.count(num2) && num2 > 0) {
                num2/=10;        // Dividing by 10 to find the prefixes of num2
            }
            
            if(num2 > 0) {   
                // If (num > 0), it means that we have found one of the prefixes of num2 in the set
                result = max(result, (int)(log10(num2)+1));     // (log10(num2)+1) will give number of digits in prefix
            }
        }
        
        return result;
        
    }
    
    
    // Approach 2: Using Trie Data Structure
    //T.C : O(m*log10(M) + n*log10(N))
    //S.C : O(m*log10(M)) for storing elements of arr1 in Trie
    struct TrieNode {
        // int data;    // Not required as we can check using child pointers
        TrieNode* children[10];
    };
    
    TrieNode* getTrieNode() {
        
        TrieNode* node = new TrieNode();
        for(int i = 0; i < 10; i++) {
            node->children[i] = nullptr;
        }
        return node;
    }
    
    void insertNode(int num, TrieNode* root) {
        // Crawler Pointer which crawls/traverse the Trie 
        TrieNode* crawl = root;
        string numStr = to_string(num);     // Converting to string to add easily in Trie
        
        for(char ch: numStr) {
            int idx = ch-'0';       // Index of the current digit in children array
            
            // If the pointer at this index in children array is nullptr,
            // insert the current digit at this pointer
            if(!crawl->children[idx]) {      
                crawl->children[idx] = getTrieNode();
            }
            
            // Moving crawler pointer ahead
            crawl = crawl->children[idx];
        }
    }
    
    int searchNode(int num, TrieNode* root) {
        TrieNode* crawl = root;
        string numStr = to_string(num); 
        int length = 0;     // For storing length of longest prefix
        
        for(char ch: numStr) {
            int idx = ch-'0';       // Index of the current digit in children array
            
            // If the pointer at this index in children array is not a nullptr,
            // common prefix is found using current num
            // Increase the length of prefix
            if(crawl->children[idx]) {      
                length++;
                // Moving crawler pointer ahead
                crawl = crawl->children[idx];
            }
            else {
                // If the pointer at this index in children array is a nullptr,
                // common prefix not found using current num
                break;  // No need to check for remaining digits in Trie
            }
            
        }
        
        return length;
    }
    
    int longestCommonPrefix2(vector<int>& arr1, vector<int>& arr2) {
        
        TrieNode* root = getTrieNode();
        
        // Inseting the numbers of arr1 in Trie
        for(int num: arr1) {
            insertNode(num, root);
        }
        
        int result = 0;
        // Searcing the numbers of arr2 in Trie and returning length of longest prefix
        for(int num: arr2) {
            result = max(result, searchNode(num, root));
        }
        
        return result;
    }
    
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Approach 1: Using set to store all possible prefixes
        // return longestCommonPrefix1(arr1, arr2);
        
        // Approach 2: Using Trie Data Structure
        return longestCommonPrefix2(arr1, arr2);
    }
};