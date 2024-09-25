struct TrieNode {
    int prefixCount = 0;        // For storing count of prefix of current node 
    TrieNode* children[26];     // Array for storing the pointers to characters from a to z in Trie
};

class Solution {
public:
    TrieNode* getTrieNode() {
        TrieNode* node = new TrieNode();
        for(int i = 0; i < 26; i++) {
            node->children[i] = nullptr;     // Assigning all the children array elements to nullptr
        }       
        node->prefixCount = 0;      // Count of prefix of current node initialized as 0
        return node;
    }
    
    void insertNode(string word, TrieNode* root) {
        // Crawler Pointer which crawls/traverse the Trie 
        TrieNode* crawl = root;
        for(char ch: word) {
            int idx = ch-'a';   // Index of the current character in children array
            
            // If the pointer at this index in children array is nullptr,
            // insert the current character at this pointer
            if(!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();   
            }
            // Increasing count of prefix for curent character
            crawl->children[idx]->prefixCount+=1;
            // Moving crawler pointer ahead
            crawl = crawl->children[idx];
        }
    }
    
    int getScore(string word, TrieNode* root) {
        TrieNode* crawl = root; 
        int score = 0;  // For storing sum of count of prefix for current word
        for(char ch: word) {
            int idx = ch-'a';   // Index of the current character in children array
            
            // If the pointer at this index in children array is not a nullptr
            // (This condition is optional here as all the characters will be present in Trie)
            if(crawl->children[idx]) {
                score += crawl->children[idx]->prefixCount;
            }
            crawl = crawl->children[idx];
        }
        return score;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = getTrieNode();
        
        // Creating a prefix tree from words array
        for(string word: words) {
            insertNode(word, root);
        }
        
        vector<int> result;
        for(string word: words) {
            int score = getScore(word, root);
            result.push_back(score);
        }
        
        return result;
    }
};