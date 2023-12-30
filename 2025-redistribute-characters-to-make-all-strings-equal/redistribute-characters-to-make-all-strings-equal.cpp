class Solution {
public:
    bool makeEqualUsingMap(vector<string>& words) {
        // Using Unordered Map
        unordered_map<char,int> count;
        int n = words.size();

        for(string str: words) { 
            for(char ch: str) {
                count[ch]++;
            }
        }

        for(auto it: count) {
            int freq = it.second;
            // If count of character is not divisible
            // by n, then the character cannot be 
            // distributed among each word in words array 
            if(freq % n != 0) {
                return false;
            }
        }

        return true;
    }

    bool makeEqualUsingArray(vector<string>& words) {
        // Using Array/Vector
        vector<int> count(26, 0);
        int n = words.size();

        for(string str: words) { 
            for(char ch: str) {
                // Converting to ASCII value and storing
                count[ch - 'a']++;
            }
        }

        for(auto freq: count) {
            // If count of character is not divisible
            // by n, then the character cannot be 
            // distributed among each word in words array 
            if(freq % n != 0) {
                return false;
            }
        }

        return true;
    }

    // Using STL and lambda
    bool makeEqualUsingSTLLambda(vector<string>& words) {
        vector<int> count(26, 0);
        int n = words.size();

        for(string str: words) { 
            for(char ch: str) {
                // Converting to ASCII value and storing
                count[ch - 'a']++;
            }
        }

        // Lambda function passed to all_of() STL
        /*
            Since 'count' vector contains integer values so
            we passed 'int freq' as parameter to lambda function.
            Since 'n' is not passed to lambda function and is 
            taken from outside the lambda function, therefore
            we passed '&' symbol inside []
        */
        auto lambda  = [&] (int freq) {
            return (freq % n) == 0;
        };  // don't forget semicolon here

        // all_of() STL checks whether all the elements in 
        // the container ('count' here) satisfies a given
        // condition (written in lambda) 
        return all_of(count.begin(), count.end(), lambda);

        // Short hand notation for lambda function:
        // return all_of(count.begin(), count.end(), [&] (int freq) {
        //     return (freq % n) == 0;
        // });
    }

    bool makeEqual(vector<string>& words) {
        // return makeEqualUsingMap(words);

        // return makeEqualUsingArray(words);

        return makeEqualUsingSTLLambda(words);
    }
};