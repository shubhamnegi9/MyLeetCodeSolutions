class Solution {
public:
    string customSortString(string order, string s) {
        
        // Using lambda function
        auto myComp = [&order](char ch1, char ch2) {
            return order.find(ch1) < order.find(ch2);
        };

        sort(s.begin(), s.end(), myComp);

        return s;
    }
};